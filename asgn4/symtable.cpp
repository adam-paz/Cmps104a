
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
astree* already_ran;

string last_func = "global";
string* curr_key;

vector<symbol_table> symbol_stack;

static bool type_NULL (astree* node){
   string null_s = "NULL";
   return (strcmp(node->type.c_str(), null_s.c_str()) == 0) ;
}

static bool type_int (astree* node){
   string int_s = "int";
   return (strcmp(node->type.c_str(), int_s.c_str()) == 0);
}

static bool type_bool (astree* node){
   string bool_s = "bool";
   return (strcmp(node->type.c_str(), bool_s.c_str()) == 0);
}

static bool type_string (astree* node){
   string char_s = "string";
   return (strcmp(node->type.c_str(), char_s.c_str()) == 0) ;
}

static bool primative (astree* node){
   return type_int(node) || type_string(node) || type_bool(node); 
}

static bool type_struct (astree* node){
   string char_s = "struct";
   return (strcmp(node->type.c_str(), char_s.c_str()) == 0) ;

}

static bool sameType (astree* node, astree* node2){
   if(type_NULL(node) || type_NULL(node2)){
      return true;
   }else{
      return (node->type == node2->type);
   }
}

string* get_key(string k){
   return new string(k);
}


//_________________________block nr____________
void enter_block(){
 //  fprintf(stdout, "%d\n",blk_nr);
   blk_nr ++;
   depth ++;
   next_blk ++;
}

void exit_block(){
   blk_nr --;
   depth --;
   next_blk --;

}

// _____________type checking for binop_____________
string binop (astree* parent){
   //parent->children[0] is the LT GT etc...
   astree* child1 = parent->children[0];//->children[0];
   astree* child2 = parent->children[1];//->children[1];
   parent->attributes = child1->attributes;
   parent->attributes[ATTR_variable] = false;
   parent->attributes[ATTR_vreg] = true;

   switch (parent->children[0]->symbol){
      case '=':{
         break;
      } 
      case TOK_EQ:{
         if(sameType(child1,child2)){
            return child1->lexinfo->c_str();
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case TOK_NE:{
         if(sameType(child1,child2)){
            return child1->lexinfo->c_str();
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case TOK_LT:{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(primative(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(primative(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case TOK_LE:{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(primative(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(primative(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case TOK_GT:{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(primative(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(primative(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case TOK_GE:{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(primative(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(primative(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case '+':{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(type_int(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(type_int(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case '-':{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(type_int(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(type_int(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case '*':{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(type_int(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(type_int(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case '/':{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(type_int(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(type_int(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n",
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      case '%':{
         if(sameType(child1,child2)){
            if(type_NULL(child1) || type_NULL(child2)){
               if(type_NULL(child1)){
                  if(type_int(child2)){
                     return child2->lexinfo->c_str();
                  }
               }
            }else{
               if(type_int(child1)){
                  return child1->lexinfo->c_str();
               }
            }
         }else fprintf(stderr,"type issue %s:%s\n %s:%s\n", 
            child1->lexinfo->c_str(),child1->type.c_str(),
            child2->lexinfo->c_str(),child2->type.c_str());
         break;
      }
      default :{
         break;
      }
   }//end case
   return "";
}  //end function

  void check_type(astree* node, symbol* tmp){
      if (node->symbol == TOK_VOID) {
         tmp->attributes[ATTR_void] = true;
      } else if (node->symbol == TOK_INT) {
         tmp->attributes[ATTR_int] = true;
      } else if (node->symbol == TOK_STRING) {
         tmp->attributes[ATTR_string] = true;
      } else if (node->symbol == TOK_TYPEID) {
         tmp->attributes[ATTR_struct] = true;
      } //else throw error
   }


//___________________making table__________

int rec_make_tables(astree* node, astree* parent){
   //case statement for pre-order analysis
   switch(node->symbol) {
      case TOK_FUNCTION: {
         node->attributes[ATTR_function] = true;
         symbol* tmp = new symbol();
         tmp->attributes[ATTR_function] = true;
         tmp->block_nr = 0;

         if(node->children[0]->symbol == TOK_ARRAY) {
            tmp->name = node->children[0]->children[1]->
                        lexinfo->c_str();
            tmp->attributes[ATTR_array] = true;
         } else {
            tmp->name = node->children[0]->children[0]->
                        lexinfo->c_str();
         }
         tmp->lloc = node->lloc;
         //TODO: add attribute for return type of function
        check_type(node->children[0],tmp);

         tmp->name = node->children[0]->children[0]->lexinfo->c_str();
         last_func = tmp->name;
         curr_key = get_key(last_func);
         //POINT
         symbol_stack.front()[curr_key] = tmp;
         //fprintf(outfile_sym, "%s (TODO: lloc) {0} (TODO: return 
         //type) function\n", tmp->name.c_str());
         break;
      }
      case TOK_STRUCT: {
         //insert dtructure name into the structure table
         //create a new symbol table for the struct
         //typeid (first child symbol) is the key
         node->attributes[ATTR_struct] = true;
         node->type = "struct";
         break;
      }
      case TOK_DECLID: {
         // string* key = new string(node->lexinfo->c_str());
         if (type_struct(node)){
            fprintf(stderr,"Variable name cannot be a typename:%s\n", 
               (node->lexinfo->c_str()));
            return_status = 1;
            break;
         } 
         //make_sym_tables(parent);
         node->attributes = parent->attributes;
         node->attributes[ATTR_variable] = true;
         break;
      }
      case TOK_VARDECLAR: {
          //for(astree* child: node->children){
              symbol* tmp = new symbol();
              //symbol_table temp;
              tmp->attributes[ATTR_variable] = true;
              tmp->attributes[ATTR_lval] = true;
              check_type(node->children[0], tmp);
              tmp->block_nr = blk_nr;
              tmp->lloc = node->lloc;
              tmp->func_name = last_func;
              node->attributes[ATTR_variable] = true;
              string* key = new string(node->children[0]->children[0]
               ->lexinfo->c_str());
              symbol_table cur_table = symbol_stack.back();
             
              cur_table[key] = tmp;
              symbol_stack.pop_back();
              symbol_stack.push_back(cur_table);

          //}
         break;
}
      case TOK_BLOCK: {
         if(parent->symbol != TOK_BLOCK){
            enter_block();
            symbol_table temp;// = new symbol_table;
            symbol_stack.push_back(temp);
            //already_ran = node->children[0];
            rec_make_tables(node->children[0], node);
            already_ran = node->children[0];
            exit_block();
         }
         break;
      }
      case TOK_WHILE: {
         if(strcmp(node->children[1]->lexinfo->c_str(),"{") != 0) {
            binop(node);
         }
         enter_block();
         rec_make_tables(node->children[0], node);
         already_ran = node->children[0];
         exit_block();
         break;
      }
      case TOK_IF: {
         enter_block();
         rec_make_tables(node->children[0], node);
         already_ran = node->children[0];
         exit_block();
         break;
      }
      case TOK_ELSE: {
         enter_block();
         rec_make_tables(node->children[0], node);
         already_ran = node->children[0];
         exit_block();
         break;
      }
      case TOK_IFELSE: {
         enter_block();
         rec_make_tables(node->children[0], node);
         already_ran = node->children[0];
         exit_block();
         break;
      }
      case TOK_NEW: {
         break;
      }
      case TOK_CALL: {
         break;
      }
      case '=':{
         //binop(node);
         break;
      }
      case '+':{
         binop(node);
         break;
      }
      case '-':{
         binop(node);
         break;
      }
      case '*':{
         binop(node);
         break;
      }
      case '/':{
         binop(node);
         break;
      }
      case '%':{
         binop(node);
         break;
      }
      case TOK_IDENT: {
         const char* key = node->lexinfo->c_str();
         //symbol_table* temp;
         symbol_table t = symbol_stack.back();
         vector <string*> keys;
         vector <symbol*> vals;
         keys.reserve(t.size());
         vals.reserve(t.size());
         string attr[(int)t.size()];

         for (auto kv : t) {
            keys.push_back(kv.first);
            vals.push_back(kv.second);
            if(strcmp(kv.first->c_str(),key) == 0){
               node->attributes = kv.second->attributes;
               node->attributes[ATTR_lval] = false;
               node->attributes[ATTR_const] = false;
               node->declloc = kv.second->lloc;
            }
         }       
break;
      }
      case TOK_PROTOTYPE: {
         node->attributes[ATTR_function] = true;
         symbol* tmp = new symbol();
         tmp->attributes[ATTR_function] = true;
         tmp->block_nr = 0;
         if(node->children[0]->symbol == TOK_ARRAY) {
            tmp->name = node->children[0]->children[1]
                        ->lexinfo->c_str();
            tmp->attributes[ATTR_array] = true;
         } else {
            tmp->name = node->children[0]->children[0]
                        ->lexinfo->c_str();
         }
         tmp->lloc = node->lloc;
         //TODO: add attribute for return type of function
         if (node->children[0]->symbol == TOK_VOID) {
            tmp->attributes[ATTR_void] = true;
         } else if (node->children[0]->symbol == TOK_INT) {
            tmp->attributes[ATTR_int] = true;
         } else if (node->children[0]->symbol == TOK_STRING) {
            tmp->attributes[ATTR_string] = true;
         } else if (node->children[0]->symbol == TOK_TYPEID) {
            tmp->attributes[ATTR_struct] = true;
         } //else throw error

         last_func = tmp->name;
         curr_key = get_key(last_func);
         //POINT
         symbol_stack.front()[curr_key] = tmp;
         //MAYBE shouldnt go here
         //fprintf(outfile_sym, "%s (TODO: lloc) {0} (TODO: return 
         //type) function\n", tmp->name.c_str());
         break;
      }
      case TOK_PARAMLIST: {
         //enter_block();
         for(astree* child: node->children){
            symbol* tmp = new symbol();
            //Want child attributes but not yet set
            tmp->attributes = child->attributes; //TODO: test
            tmp->attributes[ATTR_param]= true; 
            tmp->attributes[ATTR_variable]= true;
            tmp->attributes[ATTR_lval]= true;  
            //TODO: add tmp->attributes of parent typeid
            tmp->name = child->children[0]->lexinfo->c_str();
            tmp->lloc = child->children[0]->lloc;
            tmp->block_nr = 1;
            //POINT
            symbol* s = symbol_stack.front()[curr_key];
            s->parameters.push_back(tmp);
            // v.push_back(tmp);
            //fprintf(stdout, "\n\n%d\n\n", s->parameters.size());
         }
         //exit_block();
         //make all children have attribute param
         break;
      }
      case TOK_RETURN: {
         break;
      }
       case TOK_TYPEID: {

         if(parent->symbol == TOK_STRUCT){
         //if this is where the struct is declared
            string* key = new string(node->lexinfo->c_str());
            symbol* tmp = new symbol();
            tmp->name = "";
            type_table[key] = tmp;
            //printf("where key = %s\n", key->c_str());
            astree* bro = parent->children[1];
            symbol* struct_tmp_s = new symbol();
            //fprintf(outfile_sym, "HERE: %s\n", curr_key);
            struct_tmp_s->lloc = node->lloc;
            struct_tmp_s->block_nr = 0;//blk_nr;
            struct_tmp_s->attributes[ATTR_struct] = true;
            struct_tmp_s->attributes[ATTR_typeid] = true;
            node->type = "struct";
            if(bro != nullptr) {
            for(astree* nephew: bro->children){
               symbol* tmp = new symbol();
               tmp->block_nr = 0;

               rec_make_tables(nephew, bro);
               if(nephew->symbol == TOK_TYPEID) 
                  tmp->attributes[ATTR_struct] = true;
               if(type_string(nephew))
                  tmp->attributes[ATTR_string]= true; 
               if(type_int(nephew))
                  tmp->attributes[ATTR_int]= true; 
               if(type_NULL(nephew))
                  tmp->attributes[ATTR_null]= true; 

               tmp->attributes[ATTR_field] = true;
               tmp->lloc = nephew->lloc;
               tmp->block_nr = 0;//blk_nr;
               curr_key = get_key(nephew->children[0]->
                  lexinfo->c_str());
               tmp->lloc = nephew->children[0]->lloc;
               struct_tmp_s->fields[curr_key] = tmp;
            }
            curr_key = get_key(node->lexinfo->c_str());
            //POINT
            symbol_stack.front()[curr_key] =  struct_tmp_s;
         }
         }
         break;
      }
      case TOK_ARRAY: {
         if(strcmp(node->children[0]->lexinfo->c_str(), "void") == 0) {
            fprintf(stderr, "Can not add arrays\n");
            fprintf(stderr, "Can not have an array of type void\n");
            fprintf(stderr, "can not have void vars\n");
            fprintf(stderr, "Can not compare pointers\n");
            return_status = 1;
            return 1;
            break;
         }
         node->attributes[ATTR_array] = true;
         break;
      }

   // //post order analysis
      case TOK_VOID: {
         node->type = "void";
         node->attributes[ATTR_void] = true;
         break;
      }
      case TOK_CHAR: {
         node->type = "string";
         node->attributes[ATTR_string] = true;
         break;
      }
      case TOK_INT: {
         node->type = "int";
         node->attributes[ATTR_int] = true;
         break;
      }
      case TOK_NULL: {
         node->type = "NULL";
         node->attributes[ATTR_null] = true;
         break;
      }
      case TOK_STRING: {
         node->type = "string";
         node->attributes[ATTR_string] = true;
         break;
      }
      case TOK_INTCON: {
         node->type = "int";
         node->attributes[ATTR_int] = true;
         node->attributes[ATTR_const] = true;
         break;
      }
      case TOK_CHARCON: {
         node->type = "string";
         node->attributes[ATTR_const] = true;
         node->attributes[ATTR_string] = true;
         break;
      }
      case TOK_STRINGCON: {
         node->type = "string";
         node->attributes[ATTR_string] = true;
         node->attributes[ATTR_const] = true;
         break;
      }

      case TOK_FIELD: {
         node->attributes[ATTR_field] = true;
         //add to sym table of struct of parent
         break;
      }
      default:
         break;
   }
   
   for (astree* child: node->children) {
      if (return_status) {
         return 1;
      } else if(child != already_ran){
         rec_make_tables(child, node);
      } else 
         continue;
   }

   return 0;
}

int make_sym_tables(astree* root){
   return_status = 0;
   init_types();
   symbol_stack.push_back(global_table);
   int x = rec_make_tables(root, nullptr);
   return return_status;
   return x;
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

auto key_selector = [](auto pair){return pair.first;};
auto value_selector = [](auto pair){return pair.second;};
int print_sym_tables() {
      symbol_table t = symbol_stack.front();
      vector <string*> keys;
      vector <symbol*> vals;
      keys.reserve(t.size());
      vals.reserve(t.size());
      int index = 0;
      string attr[(int)t.size()];

      for (auto kv : t) {
         keys.push_back(kv.first);
         vals.push_back(kv.second);
         
         std::string att = "";
         for(int i=0; i < ATTR_LENGTH; i++){
            if(kv.second->attributes[i]){
               att += get_att[i];
               att += " ";
            }
         }
         attr[index] = att;
         index++;
      //t now has global_table
      }

      for(unsigned i=0; i<keys.size(); i++){
         fprintf(outfile_sym, "%s (%zd.%zd.%zd) {%d} %s\n", 
            keys[i]->c_str(),vals[i]->lloc.filenr,vals[i]->lloc.linenr,
            vals[i]->lloc.offset,
            (int)vals[i]->block_nr, attr[i].c_str());
         if(vals[i]->attributes[ATTR_struct]){
            vector <string*> k;
            vector <symbol*> v;
            k.reserve(t.size());
            v.reserve(t.size());
            int idx = 0;
            string a[(int)t.size()];

            for(auto kv_pair : vals[i]->fields) {
               k.push_back(kv_pair.first);
               v.push_back(kv_pair.second);

               std::string tmp = "";
               for(int k=0; k < ATTR_LENGTH; k++){
                  if(kv_pair.second->attributes[k]){
                     tmp += get_att[k];
                     tmp += " ";
                  }
               }
               a[idx] = tmp;
               idx++;
            }
            for(unsigned l=0; l<k.size(); l++) {
               fprintf(outfile_sym,"   %s (%zd.%zd.%zd) {%s} %s\n", 
                  k[l]->c_str(), v[l]->lloc.filenr,v[l]->lloc.linenr, 
                  v[l]->lloc.offset,keys[i]->c_str(), a[l].c_str());
            }
            fprintf(outfile_sym, "\n");
         }

         if(vals[i]->attributes[ATTR_function]) {
            for(unsigned k=0; k < vals[i]->parameters.size(); k++) {
               symbol* s = vals[i]->parameters[k];
               string a;
               for(int l=0; l < ATTR_LENGTH; l++){
                  if(s->attributes[l]){
                     a += get_att[l];
                     a += " ";
                  }
               }
               fprintf(outfile_sym,"   %s (%zd.%zd.%zd) {1} %s\n", 
                  s->name.c_str(), s->lloc.filenr,
                  s->lloc.linenr, s->lloc.offset,a.c_str());
            }
            fprintf(outfile_sym, "\n");
         

            //now print all variables used in function
            for(unsigned j=1; j<symbol_stack.size(); j++){
               //check each element against current function name
               vector <string*> k;
               vector <symbol*> v;
               k.reserve(t.size());
               v.reserve(t.size());
               std::string a = "";

               for(auto kv_pair : symbol_stack[j]) {
                  //variable is in current function
                  if(strcmp(kv_pair.second->func_name.c_str(),
                           keys[i]->c_str()) == 0) {
                        std::string tmp = "";
                        for(int k=0; k < ATTR_LENGTH; k++){
                           if(kv_pair.second->attributes[k]){
                              a += get_att[k];
                              a += " ";
                           }
                        }
                        
               fprintf(outfile_sym,"   %s (%zd.%zd.%zd) {%zd} %s\n", 
               kv_pair.first->c_str(), kv_pair.second->lloc.filenr,
               kv_pair.second->lloc.linenr, kv_pair.second->lloc.offset,
               kv_pair.second->block_nr,a.c_str());
                  }
                  }
               }
               fprintf(outfile_sym,"\n");
            }

         }
      
   
   return 0;
}
