// $Id: lyutils.h,v 1.10 2016-10-06 16:42:53-07 - - $
//-------------------------------------------------|
// lyutils from example code with added FILE* for 
// the output file of .tok used 
// by Adam Paz and Noah Brown for Assignment 2.
//-------------------------------------------------|

#ifndef __UTILS_H__
#define __UTILS_H__

// Lex and Yacc interface utility.

#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

#include "astree.h"
#include "auxlib.h"

extern FILE* yyin;
extern FILE* outfile_tok;
extern FILE* outfile_sym;
extern FILE* outfile_oil;

extern char* yytext; 
extern int yy_flex_debug;
extern int yydebug;
extern size_t yyleng; 
extern astree* yyparse_astree;

int yylex();
int yylex_destroy();
int yyparse();
void yyerror (const char* message);
astree* new_parseroot(void);
#define YYEOF 0

struct lexer {
   static bool interactive;
   static location lloc;
   static size_t last_yyleng;
   static vector<string> filenames;
   static const string* filename (int filenr);
   static void newfilename (const string& filename);
   static void advance();
   static void newline();
   static void badchar (unsigned char bad);
   static void badtoken (char* lexeme);
   static void include();
};

struct parser {
   static astree* root;
   static const char* get_tname (int symbol);
};

#define YYSTYPE astree*
#include "yyparse.h"

#endif

