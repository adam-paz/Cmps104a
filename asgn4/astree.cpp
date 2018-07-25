// $Id: astree.cpp,v 1.8 2016-09-21 17:13:03-07 - - $
//-------------------------------------------------|
// astree unmodified from example code used
// by Adam Paz and Noah Brown for Assignment 2.
//-------------------------------------------------|


#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "astree.h"
#include "string_set.h"
#include "lyutils.h"

// #include "symtable.h"


string get_attr[ATTR_LENGTH] = {"void", "int", "null", "string", 
         "struct","array", "function", "variable", "field", 
         "typeid", "param", "lval", "const", "vreg", "vaddr"};

astree::astree (int symbol_, const location& lloc_, const char* info) {
   symbol = symbol_;
   lloc = lloc_;
   lexinfo = string_set::intern (info);
   // vector defaults to empty -- no children
}

astree::~astree() {
   while (not children.empty()) {
      astree* child = children.back();
      children.pop_back();
      delete child;
   }
   if (yydebug) {
      fprintf (stderr, "Deleting astree (");
      astree::dump (stderr, this);
      fprintf (stderr, ")\n");
   }
}

astree* astree::adopt (astree* child1, astree* child2) {
   if (child1 != nullptr) children.push_back (child1);
   if (child2 != nullptr) children.push_back (child2);
   return this;
}

astree* astree::adopt_sym ( int symbol_, astree* child) {
   this->symbol = symbol_;
   if(child != nullptr){
      return adopt (child);
   }
   else{
      return this;
   }
}


void astree::dump_node (FILE* outfile) {
   fprintf (outfile, "%p->{%s %zd.%zd.%zd \"%s\":",
            this, parser::get_tname (symbol),
            lloc.filenr, lloc.linenr, lloc.offset,
            lexinfo->c_str());
   for (size_t child = 0; child < children.size(); ++child) {
      fprintf (outfile, " %p", children.at(child));
   }
}

void astree::dump_tree (FILE* outfile, int depth) {
   fprintf (outfile, "%*s", depth * 3, "");
   dump_node (outfile);
   fprintf (outfile, "\n");
   for (astree* child: children) child->dump_tree (outfile, depth+ 1);
   fflush (NULL);
}

void astree::dump (FILE* outfile, astree* tree) {
   if (tree == nullptr) fprintf (outfile, "nullptr");
                   else tree->dump_node (outfile);
}

void astree::print (FILE* outfile, astree* tree, int depth) {
   std::string attr = "";
   for(int i=0; i < ATTR_LENGTH; i++){
      if(tree->attributes[i]){
         attr += get_attr[i];
         attr += " ";
      }
   }
   if(tree->symbol == TOK_IDENT && tree->declloc.filenr != 0) {
      fprintf (outfile, "; %*s", depth * 3, "");
      fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd) %s (%zd.%zd.%zd)\n",
         parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
         tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset, 
         attr.c_str(), tree->declloc.filenr, tree->declloc.linenr,
         tree->declloc.offset);
      for (astree* child: tree->children) {
         astree::print (outfile, child, depth + 1);
      }
   } else {
   fprintf (outfile, "; %*s", depth * 3, "");
   fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd) %s\n",
            parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
            tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset, 
            attr.c_str());
   for (astree* child: tree->children) {
      astree::print (outfile, child, depth + 1);
   }
   }
}

void destroy (astree* tree1, astree* tree2) {
   if (tree1 != nullptr) delete tree1;
   if (tree2 != nullptr) delete tree2;
}

void errllocprintf (const location& lloc, const char* format,
                    const char* arg) {
   static char buffer[0x1000];
   assert (sizeof buffer > strlen (format) + strlen (arg));
   snprintf (buffer, sizeof buffer, format, arg);
   errprintf ("%s:%zd.%zd: %s", 
              lexer::filename (lloc.filenr), lloc.linenr, lloc.offset,
              buffer);
}

//new astree is made with a new symbol at the root and two new children
astree* create_astree(int symbol, astree* one, astree* two){
   astree* root = new astree(symbol, one->lloc,one->lexinfo->c_str());
   root->adopt(one, two);
   return root;
}

//new tree is made with a new symbol at the root and 3 new children
astree* create_astree_one(int symbol, astree* one, astree* two, 
                    astree* three){
   astree* root = new astree(symbol,one->lloc, one->lexinfo->c_str());
   root->adopt(one, two);
   root->adopt(three);
   return root;
}

astree* astree::changeSym(int sym, astree* root){
   root->symbol = sym;
   return root;
}
// ___________________________________________________
//    Sym Table Stuff
//___________________________________________________
//          HELPERS
