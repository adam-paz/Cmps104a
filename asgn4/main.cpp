//--------------------------------------------------------------------|
// Authors: Noah Brown, Adam Paz
// Date: 4/18/17
// Class: CS104a - Assignment 2
// File: main.cpp - Takes files and options as specified, gets 
//                  successive tokens using yylex() repeatedly. 
//                  Outputs data gathered to a .tok file of the same 
//                  name as the input, and dumps a string set of 
//                  tokens to the .str file.
//--------------------------------------------------------------------|
#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <wait.h>
#include <unistd.h>

#include "string_set.h"
#include "astree.h"
#include "lyutils.h"
#include "auxlib.h"
#include "symtable.h"
//#include "yyparse.h"
const string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;
int parse_rc;

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

void getToken() {
   if (outfile_tok == NULL) {
      fprintf(stderr, "Error in writing to .tok file");
   }

   /*for(;;) {
      int tok = yylex();
      if(yy_flex_debug) {
         fflush(NULL);
      }
      if (tok == YYEOF){ 
         break;
      }
      yylval = new astree (tok, lexer::lloc, yytext);
      fprintf(outfile_tok, "%2zu %2zu.%03zu   %3d %-14s (%s)\n",\
              yylval->lloc.filenr,yylval->lloc.linenr,\
              yylval->lloc.offset, tok,\
              parser::get_tname(yylval->symbol), yytext);
      
      const string* token = string_set::intern(yytext);
      (void) token;
   }*/
   parse_rc = yyparse();
   fclose(outfile_tok);
}      
 
int main (int argc, char** argv) {
   int debugflag = 0;
   int cppargflag = 0;
   int parseflag = 0;
   string cppargvalue = "";
   string debugvalue = "";
   int index;
   int c;
   //Parse options using getopt
   while ((c = getopt(argc, argv, "@:lyD:")) != -1)
      switch (c) {
         case '@':
            debugflag = 1;
            debugvalue = optarg;
            break;
         case 'l':
            yy_flex_debug = 1;
            break;
         case 'y':
            yydebug = 1;
            parseflag = 1;
            break;
         case 'D':
            cppargflag = 1;
            cppargvalue = optarg;
            break;
         case '?':
            if (optopt == 'D' || optopt == '@')
               fprintf(stderr, "Option -%c needs an argument.\n", 
                        optopt);
            else if (isprint (optopt))
               fprintf(stderr, "Uknown option `-%c.\n", optopt);
            else 
               fprintf(stderr, "Unknown option character `\\x%x'.\n",
                       optopt);
             return 1;
         default:
            abort();
      }

   if(debugflag == 1) {
      printf("Parseflag = %d, lexflag = %d, cppflag = %d,\
              debugflag = %d\n", parseflag, yy_flex_debug,\
              cppargflag, debugflag);
      printf("debugvalue = %s, cppargvalue = %s.\n", \
              debugvalue.c_str(), cppargvalue.c_str());
   }

   //Filter input through C preprocessor
   index = optind;
   exec::execname = basename(argv[0]);
   char* filename = argv[index];
   //Check to verify file is an oc file
   char* dot = strrchr(filename, '.');
   if(strcmp(dot, ".oc") != 0) {
      fprintf(stderr, "File to operate on is not of .oc type");
      return EXIT_FAILURE;
   }

   //add options if necessary
   string command;
   if(!cppargvalue.empty()){
      command = CPP + " -D" + cppargvalue + filename;
   } else {
      //create command and run preprocessor
      command = CPP + " " + filename;
   }
   if(debugflag == 1) 
      printf("Command=\"%s\"\n", command.c_str());
   
   yyin = popen (command.c_str(), "r");
   //Error check created pipe, if good populate the string set
   if (yyin == NULL) {
      fprintf(stderr, "%s: %s: %s\n", exec::execname.c_str(), \
              command.c_str(), strerror(errno));
      return EXIT_FAILURE;
   } else {
      dot = '\0';
      char outname_tok[LINESIZE];
      strcpy (outname_tok, basename(filename));
      auto dot_position = strrchr(outname_tok, '.');
      *dot_position = '\0';
      strcat(outname_tok, ".tok");
      outfile_tok = fopen(outname_tok, "a");
      getToken();

      int pclose_rc = pclose(yyin);
      eprint_status (command.c_str(), pclose_rc);
      if (pclose_rc != 0) 
         return EXIT_FAILURE;
   }
   // Make symbol tables
   //output to sym
   //outfile_sym = fopen("symbol.sym", "w");
   char outname_sym[LINESIZE];
   strcpy(outname_sym, basename(filename));
   auto dot_po = strrchr(outname_sym, '.');
   *dot_po = '\0';
   strcat(outname_sym, ".sym");
   outfile_sym = fopen(outname_sym, "w");
   int status = make_sym_tables(yyparse_astree);


   //Dump output to file *File name cannot exceed 1024//
   char outname_str[LINESIZE];
   char outname_ast[LINESIZE];


   strcpy(outname_str, basename(filename));
   auto dot_position = strrchr(outname_str, '.');
   *dot_position = '\0';
   strcat(outname_str, ".str");
   if(debugflag == 1) {
      printf("Outfile name = %s\n", outname_str);
   }
   FILE* outfile_str = fopen(outname_str, "w");
   string_set::dump(outfile_str);
   fclose(outfile_str);

   strcpy(outname_ast, basename(filename));
   auto dot_pos = strrchr(outname_ast, '.');
   *dot_pos = '\0';
   strcat(outname_ast, ".ast");
   FILE* outfile_ast = fopen(outname_ast, "w");


   print_sym_tables();
   
   if(debugflag == 1) {
      for (index=optind; index < argc; index++)
         printf("Non-option argument %s\n", argv[index]);
   }
   //printf("parse_rc = %d\n", parse_rc);
   if (parse_rc) {
      errprintf("parse failed");
   } else {
     // printf("outfile name = %s\n", outname_ast)
      astree::print(outfile_ast, yyparse_astree);
      //emit_sm_code(parser::root);
    //  printf("finished print\n");
      delete(yyparse_astree);
   }
   fclose(outfile_ast);
   if(status) return EXIT_FAILURE; 
   else return EXIT_SUCCESS;
}

