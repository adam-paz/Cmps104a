
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
#include "symtable.h"


// #include "symtable.h"

string get_att[ATTR_LENGTH] = {"void", "int", "null", "string", 
         "struct","array", "function", "variable", "field", 
         "typeid", "param", "lval", "const", "vreg", "vaddr"};

symbol_table type_table ; //table for holding typenames
symbol_table struct_table; //table for holding structs
symbol_table var_table;
symbol_table global_table;
int blk_nr = 0;
int next_blk = 1;
int depth = 0;
int return_status;

string last_func = "global";
string* curr_key;

vector<symbol_table*> symbol_stack(100, nullptr);
symbol_table* struct_stack = new symbol_table();

attr_bitset set_attributes(astree* node) {
   attr_bitset attr = node->attributes;
   const auto& n = struct_stack->find(node->lexinfo);
   if(n != struct_stack->end()) {
      attr[ATTR_struct] = true;
      return attr;
   }
   switch (node->symbol) {
      case TOK_VOID:   attr[ATTR_void] = true;
                       break;
      case TOK_INT:    attr[ATTR_int] = true;
                       break;
        case TOK_NULL:      attr[ATTR_null] = true;
                            attr[ATTR_const] = true;
                            break;
        case TOK_STRING:    attr[ATTR_string] = true;
                            break;
        case TOK_STRUCT:    attr[ATTR_struct] = true;
                            break;
        case TOK_ARRAY:     attr[ATTR_array] = true;
                            break;
        case TOK_TYPEID:    attr[ATTR_struct] = true;
                            break;
        case TOK_FUNCTION:  attr[ATTR_function] = true;
                            break;
        case TOK_STRINGCON: attr[ATTR_string] = true;
                            attr[ATTR_const] = true;
                            break;
        case TOK_FIELD:     attr[ATTR_field] = true;
                            break;
        case TOK_IDENT:     attr[ATTR_lval] = true;
                            break;
        case TOK_DECLID:    attr[ATTR_lval] = true;
                            break;
        case TOK_INTCON:    attr[ATTR_int] = true;
                            attr[ATTR_const] = true;
                            break;
    }
   return attr;
}

void handle_array(astree* node) {
   node->lexinfo = node->children[1]->lexinfo;
   node->attributes |= node->children[0]->attributes;

   const auto& sym = node->node->find(node->lexinfo);
   assert(sym != node->node->end());
   symbol* second_sym = sym->second;
   second_sym->attributes |= node->attributes;

   return;

}
 
void make_node(astree* node) {
   if(node == nullptr)
      return;
   if(symbol_stack[blk_nr] == nullptr) {
      vector<symbol_table*>::iterator it;
      it = symbol_stack.begin() + blk_nr;
      symbol_stack.insert(it, new symbol_table());
   }
   if (node->symbol == TOK_VARDECLAR) {
      symbol* sym = new symbol();
      sym->lloc = node->lloc;
      sym->block_nr = blk_nr;
      sym->attributes = set_attributes(node->children[0]);
      sym->parameters = nullptr;
      sym->fields = nullptr;
      //sym->fields = new symbol_table();
      //sym->attributes |= parent->attributes;

      symbol_stack[blk_nr]->insert(symbol_entry(node->children[0]->
            children[0]->lexinfo, sym));
      node->node = symbol_stack[blk_nr];
      node->block_nr = sym->block_nr;
      node->attributes = sym->attributes;
      node->children[0]->children[0]->attributes |= sym->attributes;
      node->children[0]->children[0]->attributes[ATTR_variable] = true;

   } else {
      symbol* sym = new symbol();
      sym->lloc = node->lloc;
      sym->block_nr = blk_nr;
      if((node->symbol == TOK_FUNCTION) | (node->symbol == 
               TOK_PROTOTYPE)) {
         sym->attributes = set_attributes(node);
      } else {
         sym->attributes = set_attributes(node);
      }
      if(node->symbol == TOK_STRINGCON) {
         sym->attributes[ATTR_string]=true;
         sym->attributes[ATTR_const]=true;
      }
      sym->parameters = nullptr;
      sym->fields = nullptr;
      sym->fields = new symbol_table();

      symbol_stack[blk_nr]->insert(symbol_entry(node->lexinfo, sym));
      node->node = symbol_stack[blk_nr];
      node->block_nr = sym->block_nr;
      node->attributes = sym->attributes;
   }

   if (node->symbol == TOK_ARRAY) {
      handle_array(node);
   }

   return;
}
     
void make_child(astree* node,symbol_table* fields){
   if(node == nullptr) return;

   symbol* sym = new symbol();
   sym->lloc = node->lloc;
   sym->block_nr = 0;
   sym->attributes = set_attributes(node);
   sym->parameters = nullptr;
   sym->fields = nullptr;
   sym->fields = new symbol_table();
   sym->attributes[ATTR_field] = true;
   if(sym->attributes[ATTR_struct]){
      sym->struct_type = node->lexinfo;
   }
   fields->insert(symbol_entry(node->children[0]->lexinfo, sym));
   node->node = fields;
   node->attributes = sym->attributes;
   // astree* child;
   // try {
   //    child = node->children.at(0);
   // } catch (out_of_range& e) {
   //    return;
   // }
   //make_child(child, name, fields);

   return;

}
void make_struct(astree* node) {
   const string* name = node->children[0]->lexinfo;
   const auto& n = struct_stack->find(name);
   symbol* sym;
   if(n != struct_stack->end()) {
      sym = n->second;
   } else {
      sym = new symbol();
      sym->lloc = node->lloc;
      sym->block_nr = 0;
      sym->attributes = set_attributes(node);
      sym->parameters = nullptr;
      sym->fields = nullptr;
      sym->fields = new symbol_table();
   }
   node->block_nr = 0;
   node->attributes[ATTR_struct] = true;
   node->node = struct_stack;
   if (node->children.size() > 1) {
   for(size_t child = 0; child < node->children[1]->children.size(); 
                child++) {
      
         make_child(node->children[1]->children[child], 
                sym->fields);
   }
}
   struct_stack->insert(symbol_entry(name, sym));

   return;

}

void make_func(astree* node) {
   assert(node != nullptr);

   assert (node->children[0] != nullptr);
   node->attributes |= node->children[0]->attributes;
   for (size_t i=0; i< node->children[1]->children.size(); i++) {
      astree* child = node->children[1]->children[i];

      child->children[0]->attributes |= child->attributes;
      child->children[0]->attributes[ATTR_param] = true;
      child->children[0]->attributes[ATTR_variable] = true;
      child->children[0]->attributes[ATTR_lval] = true;
      child->children[0]->block_nr = 1;

      assert (child->node != nullptr);
      const auto& n = child->node->find(child->children[0]->lexinfo);
      assert(n != node->node->end());
      n->second->attributes = child->children[0]->attributes;
   }

   return;
}


void make_sym_tables(astree* node) {
   vector<symbol_table*>::iterator it;
   
   //PRE order actions
   switch (node->symbol) {
      case TOK_STRUCT:
         make_struct(node);
         return;
      case TOK_BLOCK:
         blk_nr++;
         break;
   }

   //recursive call
   for( size_t child = 0; child < node->children.size(); child++ ) {
      make_sym_tables(node->children[child]);
   }

   //Post order actions
   switch (node->symbol) {
      case TOK_FUNCTION: 
         make_func(node);
         make_node(node);
         break;
      case TOK_ROOT:
         for(auto r_child : node->children) {
            r_child->block_nr = 0;
            if (r_child->symbol == TOK_VARDECLAR) {
               r_child->children[0]->children[0]->block_nr = 0;
            }
         }
      case TOK_BLOCK:
         it = symbol_stack.begin() + blk_nr;//symbol_stack.front() 
         symbol_stack.insert(it, nullptr);
         //blk_nr--;
      default:
         make_node(node);
         break;
   }  

   return; 
}
string get_attributes(astree* node, const char* struct_name,
                                     const char* type_name) {
   std::string att = "";
   for(int i=0; i < ATTR_LENGTH; i++) {
      if(node->attributes[i]) {
         att += get_att[i];
         att += " ";
         if (i == 8) {
            att += "{";
            att += struct_name;
            att += "} ";
         }
         if((i == 4) && (node->attributes[8]) | (node->attributes[6])  
                                              |(node->attributes[10])
             | (node->attributes[7])) {
            att += "\"";
            att += type_name;
            att += "\" ";
         }
      }
   }
   return att;
}

void init_types(){
   string* keyA = new string ("void");
   string* keyB = new string ("int");
   string* keyC = new string ("string");
   symbol* empty = new symbol();
   empty->name = "";
    type_table[keyA]= empty;
    type_table[keyB] = empty;
    type_table[keyC] = empty;

}
void print_structs() {
   vector <const string*> keys;
   vector <symbol*> vals;
   keys.reserve(struct_stack->size());
   vals.reserve(struct_stack->size());


   int index = 0;
   int size = struct_stack->size();
   string attr [size];


   for(auto kv : *struct_stack) {
      keys.push_back(kv.first);
      vals.push_back(kv.second);

      std::string att = "";
      for(int i=0; i < ATTR_LENGTH; i++) {
         if(kv.second->attributes[i]) {
            att += get_att[i];
            att += " ";
         }
      }
      attr[index] = att;
      index++;
   }

   for(unsigned i=0; i<keys.size(); i++) {
      fprintf(outfile_sym, "%s (%zd.%zd.%zd) {0} %s\n",
         keys[i]->c_str(),vals[i]->lloc.filenr, vals[i]->lloc.linenr,
         vals[i]->lloc.offset, attr[i].c_str());
      vector <const string*> k;
      vector <symbol*> v;
      k.reserve(vals[i]->fields->size());
      v.reserve(vals[i]->fields->size());
      int idx=0;
      string a[(int)vals[i]->fields->size()];

      for(auto kv_pair : *(vals[i]->fields)) {
         k.push_back(kv_pair.first);
         v.push_back(kv_pair.second);

         std::string tmp = "";
         for(int k=0; k<ATTR_LENGTH; k++) {
            if(kv_pair.second->attributes[k]) {
               tmp += get_att[k];
               tmp += " ";
            }
         }
         a[idx] = tmp;
         idx++;
      }
      for(unsigned l=0; l<k.size(); l++) {
         fprintf(outfile_sym,"   %s (%zd.%zd.%zd) {%s} %s\n",
            k[l]->c_str(), v[l]->lloc.filenr, v[l]->lloc.linenr,
            v[l]->lloc.offset,keys[i]->c_str(), a[l].c_str());
      }
      fprintf(outfile_sym, "\n");
   }
}
auto key_selector = [](auto pair){return pair.first;};
auto value_selector = [](auto pair){return pair.second;};
int print_sym_tables(astree* node, int depth) {
   //fprintf(outfile_sym, "test1\n");
   //print_structs();
   switch(node->symbol) {
      case TOK_STRUCT: {
         if(node->attributes[ATTR_array]) {
            //write node
            break;
         } else {
            const char* struct_name=node->children[0]->lexinfo->c_str();
            string attr = get_attributes(node, "", "");
      
            string space = std::string((depth-1) * 3, ' ');
            fprintf(outfile_sym, "%s%s (%zd.%zd.%zd) {0} %s \"%s\"\n",
               space.c_str(), struct_name, 
               node->children[0]->lloc.filenr,
               node->children[0]->lloc.linenr, 
               node->children[0]->lloc.offset,
               attr.c_str(), struct_name);
                             //node->children[0]->block_nr); 

            if(node->children.size() > 1) {
               for(size_t child = 0; child < node->children[1]->
                       children.size(); child++){
                  string f_space = std::string((depth)*3, ' ');
                  string f_attr = 
                     get_attributes(node->children[1]->children[child],
                     struct_name, node->children[1]->children[child]->
                     lexinfo->c_str());

                  fprintf(outfile_sym, "%s%s (%zd.%zd.%zd) %s\n",
                                                f_space.c_str(),
                  node->children[1]->children[child]->children[0]->
                       lexinfo->c_str(),
                  node->children[1]->children[child]->lloc.filenr,
                  node->children[1]->children[child]->lloc.linenr,
                  node->children[1]->children[child]->lloc.offset,
                  f_attr.c_str());
               }
            }
            fprintf(outfile_sym, "\n");
            break;
         }
      }
      case TOK_ROOT: {
         if(node->children.empty())
            break;
         for(astree* child: node->children) {
            assert(child != nullptr);
            print_sym_tables(child, depth+1);
         }
         break;
      }
      case TOK_FUNCTION: {
         string space = std::string((depth-1) * 3, ' ');
         const char* name = node->children[0]->children[0]->lexinfo->
                                                            c_str();
         const char* ret = node->children[0]->lexinfo->c_str();
         string attr = get_attributes(node, "", ret);
         fprintf(outfile_sym, "\n%s%s, (%zd.%zd.%zd) {%d} %s\n", 
                                                   space.c_str(),
               name, node->lloc.filenr, node->lloc.linenr,
               node->lloc.offset, node->block_nr, attr.c_str());
         //print paramlist
         for(size_t child = 0; child < node->children[1]->
                                       children.size(); child++) {
            string p_space = std::string(((depth-1) *3) + 3, ' ');
            const char* ret_type = node->children[1]->children[child]->
                                                      lexinfo->c_str();
            string p_attr = get_attributes(node->children[1]
                                    ->children[child]->children[0], "",
                                            ret_type);

            fprintf(outfile_sym, "%s%s (%zd.%zd.%zd) {%d} %s\n", 
                                                      p_space.c_str(),
               node->children[1]->children[child]->children[0]->
                                                      lexinfo->c_str(),
               node->children[1]->children[child]->lloc.filenr,
               node->children[1]->children[child]->lloc.linenr,
               node->children[1]->children[child]->lloc.offset,
              node->children[1]->children[child]->children[0]->block_nr,
               p_attr.c_str());
         }
         fprintf(outfile_sym, "\n");
         print_sym_tables(node->children[2], depth+1);
         break;
      }
      case TOK_PROTOTYPE: {
         string space = std::string((depth-1) * 3, ' ');
         const char* name = node->children[0]->children[0]->lexinfo->
                                                            c_str();
         const char* ret = node->children[0]->lexinfo->c_str();
         fprintf(outfile_sym, "%s%s, (%zd.%zd.%zd) {%d} %s\n", 
                                                      space.c_str(),
               name, node->lloc.filenr, node->lloc.linenr,
               node->lloc.offset, node->block_nr, ret);
         //print paramlist
         for(size_t child = 0; child < node->children[1]->
                                          children.size(); child++) {
            string p_space = std::string(((depth-1) *3) + 3, ' ');
            fprintf(outfile_sym, "%s%s (%zd.%zd.%zd) {%d} %s\n", 
                                                      p_space.c_str(),
               node->children[1]->children[child]->children[0]->
                                                      lexinfo->c_str(),
               node->children[1]->children[child]->lloc.filenr,
               node->children[1]->children[child]->lloc.linenr,
               node->children[1]->children[child]->lloc.offset,
               node->children[1]->children[child]->block_nr,
               node->children[1]->children[child]->lexinfo->c_str());
         }
         fprintf(outfile_sym ,"\n");
         break;
      }
      case TOK_VARDECLAR: {
         //Add whitespace as needed
         string space = std::string((depth-1) * 3, ' ');
         const char* name = node->children[0]->children[0]->lexinfo->
                                                            c_str();
         const char* type = node->children[0]->lexinfo->c_str();
         string var_attr = get_attributes(node->children[0]->
                                             children[0], "", type);
         fprintf(outfile_sym, "%s%s (%zd.%zd.%zd) {%d} %s\n", 
                                                      space.c_str(),
               name, node->children[0]->lloc.filenr,
               node->children[0]->lloc.linenr,
               node->children[0]->lloc.offset,
               node->children[0]->children[0]->block_nr,
               var_attr.c_str());
         break;
      }
      default:
         if(node == nullptr)
            break;

         if(node->children.empty()) 
            break;
         for(astree* child : node->children) {
            assert(child != nullptr);
            print_sym_tables(child, depth+1);
         }
      }

   return 0;
}
//__________________________________________________//
void print_oil(int depth, string var){
   string space = std::string(depth*3, ' ');

   fprintf(outfile_oil, "%s%s", space.c_str(), var.c_str() );
}

string get_type(symbol* sym){
   string type = "";
   if(sym->attributes[ATTR_struct]){
      type = "struct s_";
      const char* name = sym->struct_type->c_str();
      type += name;
      type += "*";
   } else if (sym->attributes[ATTR_int]) {
      type = "int";
   } else if (sym->attributes[ATTR_string]) {
      type = "char*";
   }
   //add array handling
   return type;
}

string mangle(astree* node, string name) {
   string new_name;
   switch(node->symbol) {
      case TOK_WHILE: new_name = name +"_"
                      + to_string(node->lloc.filenr) + "_"
                      + to_string(node->lloc.linenr) + "_"
                      + to_string(node->lloc.offset);
                     break;
      case TOK_IF:
      case TOK_IFELSE:
                     new_name = name + "_"
                     + to_string(node->lloc.filenr) + "_"
                     + to_string(node->lloc.linenr) + "_"
                     + to_string(node->lloc.offset) + ":;";
                     break;
      case TOK_INTCON: 
      case TOK_CHARCON:
      case TOK_STRINGCON: new_name = name; 
                     break;
      case TOK_FUNCTION: new_name = "__" + name;
                     break;
      case TOK_DECLID: new_name = "_"
                           + to_string(node->block_nr) + "_" + name;
                     break;
      default: new_name = "_" + to_string(node->block_nr)
                          + "_" + node->lexinfo->c_str();
                     break;
      
   }
   return new_name;
}
void make_oil_new(astree* node, int depth){
   astree* newTypes = node->children[0];
   string out;
    if (newTypes->symbol == TOK_TYPEID) {
        out = "struct s_" +*newTypes->lexinfo +"* p0 = "+ 
              "xcalloc (1, sizeof (struct s_"
              + newTypes->lexinfo->c_str() + "));";
    } else if (node->symbol == TOK_NEWARRAY) {
         out = "char* p0 = xcalloc (" 
            + to_string(node->children[0]->lexinfo->length()-2)
            + ", sizeof (char));\n";

    }else {
        out  = "ERROR: " + *node->lexinfo+";" ;
    }
    print_oil(depth, out);
    fprintf(outfile_oil, "\n");
}



string mangle_type(astree* node, const string* name) {
   string old_type = *node->lexinfo;
    string new_type;
    if (old_type == "int") {
        new_type = "int";
    } else if (old_type == "string") {
        new_type = "char*";
    } else {
         if (name == nullptr || strcmp(name->c_str(),".") == 0)
             return  "";//"ERR" + oldTypes;
        new_type = "struct s_";
        new_type += name->c_str();
        new_type += "*";
    }
return new_type;
}
void make_oil_call(astree* node, int depth) {
    string space = std::string(depth*3, ' ');
    string out;
   // printf(outfile_oil, "%s%s")
        
         fprintf(outfile_oil, "%s__%s(", space.c_str(), 
                                 node->children[0]->lexinfo->c_str());
         for (size_t i=1; i<node->children.size(); i++) {
            astree* param = node->children[i];

             if (strcmp(param->lexinfo->c_str(),".") ==0){
                out = mangle(param->children[0], 
                                   *param->children[0]->lexinfo) +
                "->_f_" +  *param->children[1]->lexinfo->c_str() +
                ");\n";
                fprintf(outfile_oil, "%s", out.c_str());
                return;
            } else if(param->attributes[ATTR_const] | (param->symbol 
                                                   == TOK_CHARCON)) {
               fprintf(outfile_oil, "%s", param->lexinfo->c_str());

            } else if(param->symbol == TOK_INDEX){
               fprintf(outfile_oil, "\"Assert Fail\\n\");\n}\n" );
               exit(1);

            }else {
               out = mangle(param, *param->lexinfo);
               fprintf(outfile_oil, "%s", out.c_str());
            }
            if(i != node->children.size()-1) {
               fprintf(outfile_oil, ", ");
            }
         }
         fprintf(outfile_oil, ");\n");
}
void write_oil_structs() {
   //gather all struct info
   vector <const string*> keys;
   vector <symbol*> vals;
   keys.reserve(struct_stack->size());
   vals.reserve(struct_stack->size());


   int index = 0;
   int size = struct_stack->size();
   string attr [size];


   for(auto kv : *struct_stack) {
      keys.push_back(kv.first);
      vals.push_back(kv.second);

      std::string att = "";
      for(int i=0; i < ATTR_LENGTH; i++) {
         if(kv.second->attributes[i]) {
            att += get_att[i];
            att += " ";
         }
      }
      attr[index] = att;
      index++;
   }

   for(unsigned i=0; i<keys.size(); i++) {
      
      //print struct name with s_
      fprintf(outfile_oil, "struct s_%s {\n", keys[i]->c_str());
      
      //print all fields with type and f_structname_fieldname
      vector <const string*> k;
      vector <symbol*> v;
      k.reserve(vals[i]->fields->size());
      v.reserve(vals[i]->fields->size());
      for(auto kv_pair : *(vals[i]->fields)) {
         k.push_back(kv_pair.first);
         v.push_back(kv_pair.second);
      }
      for(unsigned j=0; j< k.size(); j++){
         //Make get type of a symbol
         string type = get_type(v[j]);
         fprintf(outfile_oil,"\t%s _f_%s;\n", type.c_str(), k[j]->
                                                            c_str());
      }
      fprintf(outfile_oil, "};\n\n");
   }
}
void make_oil_dec(astree* node, int depth) {
   astree* left = node->children[0]; //this will be "." in case of b.a
    astree* right = node->children[1];
    string space = std::string(depth*3, ' ');
    if (strcmp(left->lexinfo->c_str(),".") ==0)
    {
         fprintf(outfile_oil, "%s%s->%s = %s;\n", space.c_str(), 
            mangle(left->children[0], *left->children[0]->lexinfo).
                                                            c_str(), 
            mangle(left->children[1], *left->children[1]->lexinfo).
                                                            c_str(),
            right->lexinfo->c_str());
        return;
    }
   if (left->symbol != TOK_IDENT) {
   switch (right->symbol) {
         //case int x=y, char y=z
         case TOK_CALL: make_oil_call(node, depth);
                        break;
         case TOK_NULL: fprintf(outfile_oil, "NULL\n" );
                        break;
         case TOK_NEWARRAY:
         case TOK_NEW:  make_oil_new(right, depth );
                        break;


         case TOK_IDENT:     
            fprintf(outfile_oil, "%s%s %s = %s;\n", space.c_str(),
               mangle_type(left, left->lexinfo).c_str(), 
               mangle(left->children[0], *left->children[0]->lexinfo).
                                                               c_str(),
               "p0");
                             break;
         case TOK_INTCON:
         case TOK_CHARCON:
         case TOK_STRINGCON:
            fprintf(outfile_oil, "%s%s %s = %s;\n", space.c_str(),
               (mangle_type(left, left->lexinfo).c_str()),
               (mangle(left->children[0], *left->children[0]->lexinfo).
                                                               c_str()),
               (*right->lexinfo).c_str());
            break;
      
         case '+':
         case '-':       
            if (right->children.size() == 1) {
              fprintf(outfile_oil, "%s%s %s = %s %s;\n", space.c_str(),
               (mangle_type(left, left->lexinfo).c_str()),
               (mangle(left, *left->lexinfo).c_str()),
               (*right->lexinfo).c_str(), 
               (mangle(right->children[0], *right->children[0]->lexinfo)
                                                            .c_str()));
              break;
           }
         default:        
            fprintf(outfile_oil, "%s%s %s = ", space.c_str(),
               (*left->lexinfo).c_str(), (mangle(left->children[0], 
                              *left->children[0]->lexinfo)).c_str());
            string op1, op2;
            if(node->children[1]->symbol != TOK_NEW) {
               if (node->children[1]->children[0]->symbol==TOK_IDENT){
               op1 = "_" + to_string(node->children[1]->children[0]->
                                                      block_nr) + "_" +
                   node->children[1]->children[0]->lexinfo->c_str();
            } else {
               op1 = "" + *node->children[1]->children[0]->lexinfo->
                                                      c_str();
             }
            if (node->children[1]->children[1]->symbol == TOK_IDENT) {
               op2 = "_" + to_string(node->children[1]->children[1]->
                                                      block_nr) + "_" +
                   node->children[1]->children[1]->lexinfo->c_str();
            } else {
               op2 = "" + *node->children[1]->children[1]->lexinfo->
                                                               c_str();
            }
            fprintf(outfile_oil, "%s %s %s;\n", op1.c_str(), 
                     node->children[1]->lexinfo->c_str(), op2.c_str());
         }
                         break;
     }
 } else {
     switch (right->symbol) {
         //case x=y
         case TOK_IDENT:     
            fprintf(outfile_oil, "%s%s = %s;\n", space.c_str(),
               (mangle(left, *left->lexinfo)).c_str(),
               (mangle(right, *right->lexinfo)).c_str());
               //(*right->lexinfo).c_str());
            break;

         case TOK_INTCON:
         case TOK_CHARCON:
         case TOK_STRINGCON:
         case TOK_NULL:
            fprintf(outfile_oil, "%s%s = %s;\n", space.c_str(),
               (mangle(left, *left->lexinfo)).c_str(),
               (*right->lexinfo).c_str());
            break;

         default:        
            fprintf(outfile_oil, "%s%s %s = ", space.c_str(),
               (*left->lexinfo).c_str(), (mangle(left, *left->lexinfo)).
                                                               c_str());
            //make_oil_call(right, depth);
            string op1, op2;
            if(node->children[1]->symbol != TOK_NEW) {
            if (node->children[1]->children[1]->symbol == TOK_IDENT) {
               op2 = "_" + to_string(node->children[1]->children[1]->
                                                      block_nr) + "_" +
                   node->children[1]->children[1]->lexinfo->c_str();
            } else {
               op2=""+*node->children[1]->children[1]->lexinfo->c_str();
            }
            fprintf(outfile_oil, "%s %s %s;\n", op1.c_str(), node->
                           children[1]->lexinfo->c_str(), op2.c_str());
         }
                         break;
     }
   }
}

void make_oil_eq(astree* node, int depth){
   string space = std::string(depth*3, ' ');
   string var_name = "_" + to_string(node->children[0]->block_nr)+"_"+
                  node->children[0]->lexinfo->c_str();
   astree* left = node->children[0]; //this will be "." in case of b.a
   astree* right = node->children[1];
   string op1, op2;
   switch(left->symbol){
      case '.': 
               var_name = mangle(left->children[0],
                  *left->children[0]->lexinfo) + "->" 
                  + "_f_" + *left->children[1]->lexinfo;
               print_oil(depth,var_name);
               //fprintf(outfile_oil, "\n");
               break;
      case '+':
      case '-':       
               if (left->children.size() == 1) {
                  //its unary!
                  op1 = *left->lexinfo
                   + *left->children[0]->lexinfo;
                  break;
               } 
      case '/':
      case '*':       
               make_oil_eq(left, depth);
               break;
      case TOK_CALL: 
               make_oil_call(left, depth);
               break;
      default:
               if(node->children[1]->attributes[ATTR_const]) { 
                  fprintf(outfile_oil, "%s", left->lexinfo->c_str());
               } else {
                  fprintf(outfile_oil, "%s%s", space.c_str(),
                                 mangle(left, *left->lexinfo).c_str());
               } break;
    }

    fprintf(outfile_oil, " %s ", node->lexinfo->c_str());
    
    switch (right->symbol){
      case '.': 
                var_name = mangle(right->children[0],
                  *right->children[0]->lexinfo) + "->" 
                  + "_f_" + *right->children[1]->lexinfo;
               print_oil(0,var_name);
               break;
      case '+':
      case '-':       
               if (right->children.size() == 1) {
                  //its unary!
                  op1 = *right->lexinfo
                   + *right->children[0]->lexinfo;
                  break;
               } 
      case '/':
      case '*':       
               make_oil_eq(right, depth);
               break;            
      case TOK_IDENT:
               fprintf(outfile_oil, "%s;\n",mangle(right,*right->
                                                   lexinfo).c_str());
               break;
      case TOK_CALL: 
               make_oil_call(right, depth);
               fprintf(outfile_oil," ");
               break;
      default:
            if(node->children[1]->attributes[ATTR_const]) {
                     fprintf(outfile_oil, "%s",right->lexinfo->c_str());
            } else {
                     fprintf(outfile_oil, "%s", mangle(right, *right->
                                                      lexinfo).c_str());
               
            } fprintf(outfile_oil, ";\n"); 
            break;
    }
}



int i_index=1;
void make_oil_global_data( astree* node, int depth) {
   switch (node->symbol) {
      case '=': {
         make_oil_eq(node,depth);
         break;
         //fprintf(outfile_oil, "test\n");
         //make_oil_dec(node, depth);
         
      }
      case TOK_VARDECLAR:{
         //fprintf(outfile_oil, "test\n");
         make_oil_dec(node, depth);
       
         break;
      }
      case TOK_CALL: {
         make_oil_call(node, depth);
         
         break;
      }
      default: break;

   }
}

void write_oil_globals(astree* root) {
   
   fprintf(outfile_oil, "void __ocmain (void)\n{\n");
   for (astree* child: root->children) {
     
      if (child->symbol != TOK_FUNCTION && child->symbol != TOK_STRUCT)
         make_oil_global_data(child, 1);
   }
   fprintf(outfile_oil, "}\n");
      
}

void write_oil(astree* root) {
   //prologue for included files
   fprintf(outfile_oil, "#define __OCLIB_C__\n#include \"oclib.oh\"\n");
   write_oil_structs();
   write_oil_globals(root);
}



