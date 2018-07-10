//-------------------------------------------------|
// Dummy parser unmodified from example code used
// by Adam Paz and Noah Brown for Assignment 2.
//-------------------------------------------------|


%{
// prologue
#include <cassert>
#include "lyutils.h"
#include "astree.h"
#include "stdio.h"
%}

//Declarations
%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT

%token TOK_VARDECL TOK_IDENTDECL TOK_BOOL TOK_DECLID TOK_FALSE 
%token TOK_TRUE TOK_NEWSTRING TOK_RETURNVOID TOK_INDEX TOK_PROTOTYPE 
%token TOK_FUNCTION TOK_PARAMLIST


%initial-action{
  parser::root = new astree (TOK_ROOT, {0,0,0}, "<<ROOT>>");
}
%printer { astree::dump (yyoutput, $$); } <>

%right  TOK_IF TOK_ELSE
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right   TOK_POS TOK_NEG '!' TOK_NEW
%left   '[' '.' TOK_CALL
%left   '('



%start start



%%
start    : program    { $$ = $1 = nullptr;}
         ;

//Grammar Rules
program : program structdef {$$ = $1->adopt($2);}
        | program function  {$$ = $1->adopt($2);}
        | program statement {$$ = $1->adopt($2);}
        | program error '}'          { $$ = $1;}
        | program error ')'          { $$ = $1;}
        | program error ';'          { $$ = $1;}
        |                   {$$ = parser::root ;}


structdef : strfield '}'  
          {destroy($2); $$ = $1; }
          ;

strfield  : strfield fielddecl ';'
          { destroy($3); 
            $$ = $1->adopt($2); }
          | TOK_STRUCT TOK_IDENT '{' 
          { destroy($3); 
            $$=$1->adopt($2);changeSym(TOK_TYPEID,$2);}
          ;

fielddecl : basetype TOK_ARRAY TOK_IDENT 
          { $$=$2->adopt($1,$3); changeSym(TOK_FIELD,$3);}
          | basetype TOK_IDENT       
          { $$ = $1->adopt($2); changeSym(TOK_FIELD,$2) ;}
          ;

basetype  : TOK_VOID                 { $$=$1; }
          | TOK_BOOL                 { $$=$1; }
          | TOK_CHAR                 { $$=$1; }
          | TOK_INT                  { $$=$1; }
          | TOK_STRING               { $$=$1; }
          | TOK_IDENT                
          { changeSym(TOK_TYPEID, $1); 
            $$=$1; }
          ;

function  : identdecl funcargs ')' block   
          { destroy($3); 
            $$=create_astree_one(TOK_FUNCTION, $1, $2, $4); }
          | identdecl funcargs ')' ';'
          { destroy($3);destroy($4); 
            $$=create_astree(TOK_PROTOTYPE, $1, $2); }
          ;

funcargs  : funcargs ',' identdecl      
          { destroy($2); 
            $$=$1->adopt($3); }
          | '(' identdecl            
          { changeSym(TOK_PARAMLIST, $1); 
            $$=$1->adopt($2); }
          | '(' 
          { changeSym(TOK_PARAMLIST, $1); 
            $$=$1;}
          ;

identdecl : basetype TOK_IDENT       
          { $$=$1/*->adopt($2); changeSym(TOK_DECLID,$1);*/ }
          | basetype TOK_ARRAY TOK_IDENT
          { $$=$2->adopt($3,$1); changeSym( TOK_DECLID, $3);}
          ;

block     : blockstmnts '}'             
          { destroy($2); $$=$1;}
          ;

blockstmnts  : blockstmnts statement    { $$=$1->adopt( $2);}
             | '{'                      { changeSym(TOK_BLOCK,$1); 
                                        $$=$1;}
             ;

statement : block                    { $$=$1;}
          | ';'                      { $$=$1;}
          | vardecl                  { $$=$1;}
          | while                    { $$=$1;}
          | ifelse                   { $$=$1;}
          | return                   { $$=$1;}
          | expr ';'                 { $$=$1; destroy($2);}
          ;

vardecl   : identdecl '=' expr ';' 
          { destroy($4); 
            changeSym(TOK_VARDECL, $2);
            $$=$2->adopt($1,$3);}
          ;

while     : TOK_WHILE '(' expr ')' statement
          { destroy($2); destroy($4); 
            $$=$1->adopt($3, $5);}
          ;

ifelse    : TOK_IF '(' expr ')' statement %prec TOK_ELSE
          { destroy($2); destroy($4); 
            $$=$1->adopt($3,$5);}
          | TOK_IF '(' expr ')' statement TOK_ELSE statement 
          { destroy($2);destroy($4); 
            free($6); 
            $$=$1->adopt($3,$5);
            $$=$1->adopt($7); changeSym(TOK_IFELSE,$7);}
          ;

return    : TOK_RETURN ';'           
          { destroy($2); changeSym(TOK_RETURNVOID, $1); $$=$1;}
          | TOK_RETURN expr ';'      
          { destroy($3); $$=$1->adopt($2);}
          ;

expr      : expr '=' expr           { $$ = $2->adopt($1, $3);}
          | expr TOK_EQ expr        { $$ = $2->adopt($1, $3);}
          | expr TOK_NE expr        { $$ = $2->adopt($1, $3);}
          | expr TOK_LT expr        { $$ = $2->adopt($1, $3);}
          | expr TOK_LE expr        { $$ = $2->adopt($1, $3);}
          | expr TOK_GT expr        { $$ = $2->adopt($1, $3);}
          | expr TOK_GE expr        { $$ = $2->adopt($1, $3);}
          | expr '+' expr           { $$ = $2->adopt($1, $3);}
          | expr '-' expr           { $$ = $2->adopt($1, $3);}
          | expr '*' expr           { $$ = $2->adopt($1, $3);}
          | expr '/' expr           { $$ = $2->adopt($1, $3);}
          | expr '%' expr           { $$ = $2->adopt($1, $3);}
          | '+' expr %prec TOK_POS  { changeSym(TOK_POS, $1);
                                      $$ = $1->adopt($2);}
          | '-' expr %prec TOK_NEG  { changeSym(TOK_NEG, $1);
                                      $$ = $1->adopt($2);}
          | '!' expr                { $$ = $1->adopt($2);}
          | TOK_ORD expr            { $$ = $1->adopt($2);}
          | TOK_CHR expr            { $$ = $1->adopt($2);}
          | allocator               { $$ = $1;}
          | call                    { $$ = $1;}
          | '(' expr ')'            { destroy($1);destroy($3);$$=$2;}
          | variable                { $$ = $1;}
          | constant                { $$ = $1;}
          ;

allocator : TOK_NEW TOK_IDENT '('')'
          { destroy($3); destroy($4); 
            $$=$1->adopt($2);changeSym(TOK_TYPEID,$2);}
          | TOK_NEW TOK_STRING '(' expr ')'
          { destroy($3); destroy($5); changeSym( TOK_NEWSTRING,$2);
              $$ = $2->adopt($4);}
          | TOK_NEW basetype '[' expr ']'
          { destroy($3);destroy($5); 
            changeSym( TOK_NEWARRAY, $1);
            $$ = $1->adopt($2,$4); changeSym(TOK_TYPEID,$2);}
          ;

call      :  callargs ')'            { destroy($2); $$=$1;}
          | TOK_IDENT '(' ')'        { destroy($3); 
                                       changeSym( TOK_CALL,$2);
                                       $$=$2->adopt( $1);}
          ;

callargs  : callargs ',' expr        { destroy($2); 
                                       $$ = $1->adopt($3);}
          | TOK_IDENT '(' expr       { $2->adopt_sym(TOK_CALL); 
                                       $$=$2->adopt($1,$3);}
          ;

variable  : TOK_IDENT                { $$ = $1;}
          | expr '[' expr ']'        
          { destroy($4); 
            changeSym(TOK_INDEX,$2); 
            $$=$2->adopt($1, $3);}
          | expr '.' TOK_IDENT       
          { destroy($2); 
            $$ = $1->adopt($3); changeSym(TOK_FIELD,$3);}
          ; 

constant  : TOK_INTCON               { $$=$1;}
          | TOK_CHARCON              { $$=$1;}
          | TOK_STRINGCON            { $$=$1;}
          | TOK_FALSE                { $$=$1;}
          | TOK_TRUE                 { $$=$1;}
          | TOK_NULL                 { $$=$1;}
          ;


%%

//Epilogue

const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}
/*
static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != nullptr);
   return result;
}
*/
