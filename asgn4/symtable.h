// $Id: astree.h,v 1.7 2016-10-06 16:13:39-07 - - $
//-------------------------------------------------|
// astree unmodified from example code used
// by Adam Paz and Noah Brown for Assignment 2.
//-------------------------------------------------|

#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <string>
#include <vector>
using namespace std;
// #include "astree.h"
#include "auxlib.h"
#include <bitset>
#include <unordered_map>
#include <stack>
#include "astree.h"

// enum { ATTR_void, ATTR_int, ATTR_null, ATTR_string,
//        ATTR_struct, ATTR_array, ATTR_function, ATTR_variable,
//        ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const,
//        ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
//    };
//    using attr_bitset = bitset<ATTR_bitset_size>;
   
struct symbol{
    using symbol_table = unordered_map<string*, symbol*>;
    attr_bitset attributes;
    symbol_table fields;
    location lloc;
    size_t block_nr = 0;
    vector<symbol*> parameters;
    string name;
    string func_name;
};


using symbol_table = unordered_map<string*, symbol*>;
using symbol_entry = pair<const string*, symbol*>;
int print_sym_tables();
int make_sym_tables(astree* root);
void init_types();
// void insert(symbol_table , symbol_entry);
#endif

