// $Id: astree.h,v 1.7 2016-10-06 16:13:39-07 - - $
//-------------------------------------------------|
// astree unmodified from example code used
// by Adam Paz and Noah Brown for Assignment 2.
//-------------------------------------------------|

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
using namespace std;

#include "auxlib.h"
//#include "symtable.h"
#include <bitset>
#include <unordered_map>
#define ATTR_LENGTH 15

struct location {
   size_t filenr;
   size_t linenr;
   size_t offset;
};
enum { ATTR_void, ATTR_int, ATTR_null, ATTR_string,
       ATTR_struct, ATTR_array, ATTR_function, ATTR_variable,
       ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const,
       ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
   };
   using attr_bitset = bitset<ATTR_bitset_size>;

struct astree {

   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   location declloc;
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   string type;

   // Functions.
   astree (int symbol, const location&, const char* lexinfo);
   ~astree();
   astree* adopt (astree* child1, astree* child2 = nullptr);
   astree* adopt_sym (int symbol, astree* child = nullptr);
   void dump_node (FILE*);
   void dump_tree (FILE*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
   astree* changeSym(int sym, astree* root);
   attr_bitset attributes;

};

   

void destroy (astree* tree1, astree* tree2 = nullptr);

void errllocprintf (const location&, const char* format, const char*);

void free_ast (astree* root);

astree* create_astree(int symbol, astree* left, astree* right);

astree* create_astree_one(int symbol, astree* left, astree* mid, 
                    astree* right);



#endif

