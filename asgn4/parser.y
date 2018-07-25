//-------------------------------------------------|
// Dummy parser unmodified from example code used
// by Adam Paz and Noah Brown for Assignment 2.
//-------------------------------------------------|


%{
#include <cassert>

#include "lyutils.h"
#include "astree.h"

%}

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
%token ROOT IDENT

%token TOK_FUNCTION TOK_PARAMLIST TOK_PROTOTYPE TOK_NEWSTRING
%token TOK_INDEX TOK_DECLID TOK_RETURNVOID TOK_VARDECLAR

%right TOK_IF TOK_ELSE
%right '='
%left  TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left  '+' '-'
%left  '*' '/' '%'
%right TOK_POS TOK_NEG '!' TOK_NEW
%left  TOK_ARRAY TOK_FIELD TOK_FUNCTION
%left '[' '.'

%start start

%%

start       : program               {yyparse_astree = $1;}
            ;

program     : program structdef     {$$ = $1->adopt($2);}
            | program function      {$$ = $1->adopt($2);}
            | program statement     {$$ = $1->adopt($2);}
            | program error '}'     {$$ = $1;}
            | program error ';'     {$$ = $1;}
            |                       {$$ = new_parseroot();}
            ;

structdef   : TOK_STRUCT TOK_IDENT strfield '}'
                    {destroy($4); $2 = $2->changeSym( TOK_TYPEID, $2);
                    $$ = $1->adopt($2, $3);}
            | TOK_STRUCT TOK_IDENT '{' '}'
                {destroy($3, $4); $2 = $2->changeSym(TOK_TYPEID, $2);
                $$ = $1->adopt($2);}
            ;

strfield    : '{' fielddec ';'   {destroy($3); $$ = $1->adopt($2);}
            | strfield fielddec ';'
                                    {destroy($3); $$ = $1->adopt($2);}
            ;

fielddec : basetype TOK_IDENT
                {$2 = $2->changeSym(TOK_FIELD, $2); $$ = $1->adopt($2);}
            | basetype TOK_ARRAY TOK_IDENT
                {$3 = $3->changeSym(TOK_FIELD, $3); 
                        $$ = $2->adopt($1, $3);}
            ;

basetype    : TOK_VOID              {$$ = $1;}
            | TOK_CHAR              {$$ = $1;}
            | TOK_INT               {$$ = $1;}
            | TOK_STRING            {$$ = $1;}
            | TOK_IDENT             {$$ = $1->changeSym(TOK_TYPEID,$1);}
            ;

plist       : '(' identdec
                {$1 = $1->changeSym(TOK_PARAMLIST, $1);
                    $$ = $1->adopt($2);}
            | plist ',' identdec {destroy($2); $$ = $1->adopt($3);}
            ;

function    : identdec plist ')' block
                {
                    destroy($3); 
                    $$ = new astree(TOK_FUNCTION, $1->lloc, "");
                    $$ = $$->adopt($1, $2);
                    $$ = $$->adopt($4);
                }
            | identdec plist ')' ';'
                {
                    destroy($3, $4);
                    $$ = new astree(TOK_PROTOTYPE, $1->lloc, "");
                    $$ = $$->adopt($1, $2);
                }
            | identdec '(' ')' block
                {
                    destroy($3);
                    $2 = $2->changeSym(TOK_PARAMLIST,$2 );
                    $$ = new astree(TOK_FUNCTION, $1->lloc, "");
                    $$ = $$->adopt($1, $2);
                    $$ = $$->adopt($4);
                }
            | identdec '(' ')' ';'
                {
                    destroy($3, $4);
                    $2 = $2->changeSym(TOK_PARAMLIST, $2);
                    $$ = new astree(TOK_PROTOTYPE, $1->lloc, "");
                    $$ = $$->adopt($1, $2);
                }
            ;

identdec : basetype TOK_IDENT
                { 
                    $2 = $2->changeSym(TOK_DECLID, $2);
                    $$ = $1->adopt($2);
                }
            | basetype TOK_ARRAY TOK_IDENT
                {
                    $3 = $3->changeSym(TOK_DECLID,$3);
                    $$ = $2->adopt($1, $3);
                }
            ;

body        : '{' statement
                {
                    $1 = $1->changeSym(TOK_BLOCK, $1);
                    $$ = $1->adopt($2);
                }
            | body statement
                {
                    $$ = $1->adopt($2); 
                }
            ;

block       :  body '}'
                {
                    destroy($2);
                    $$ = $1->changeSym(TOK_BLOCK, $1);
                }
            | '{' '}'
                {
                    destroy($2);
                    $$ = $1->changeSym(TOK_BLOCK,$1);
                }
            ;

statement   : block                 {$$ = $1;}
            | vardec                {$$ = $1;}
            | while                 {$$ = $1;}
            | ifelse                {$$ = $1;}
            | return                {$$ = $1;}
            | exp ';'              {destroy($2); $$ = $1;}
            | ';'                   {$$ = $1;}
            ;

vardec   : identdec '=' exp ';'
                {
                    destroy($4);
                    $2 = $2->changeSym(TOK_VARDECLAR,$2);
                    $$ = $2->adopt($1, $3);
                }
            ;

while       : TOK_WHILE '(' exp ')' statement
                { 
                    destroy($2, $4);
                    $$ = $1->adopt($3, $5);
                }
            ;

ifelse      : TOK_IF '(' exp ')' statement TOK_ELSE statement
                {
                    destroy($2, $4);
                    $1->changeSym(TOK_IFELSE, $1);
                    $$ = $1->adopt($3, $5);
                    $$ = $$->adopt($7);
                }
            | TOK_IF '(' exp ')' statement %prec TOK_ELSE
                {
                    destroy($2, $4);
                    $$ = $1->adopt($3, $5);
                }
            ;

return      : TOK_RETURN ';'
                {
                    destroy($2);
                    $$ = $1->changeSym(TOK_RETURNVOID, $1);
                }
            | TOK_RETURN exp ';'
                {
                    destroy($3);
                    $$ = $1->adopt($2);
                }
            ;

exp         : binop                     {$$ = $1;}
            | unop                      {$$ = $1;}
            | allocator                 {$$ = $1;}
            | call                      {$$ = $1;}
            | '(' exp ')'               {destroy($1, $3); $$ = $2;}
            | variable                  {$$ = $1;}
            | constant                  {$$ = $1;}
            ;

binop       : exp TOK_EQ exp            {$$ = $2->adopt($1, $3);}
            | exp TOK_NE exp            {$$ = $2->adopt($1, $3);}
            | exp TOK_LT exp            {$$ = $2->adopt($1, $3);}
            | exp TOK_LE exp            {$$ = $2->adopt($1, $3);}
            | exp TOK_GT exp            {$$ = $2->adopt($1, $3);}
            | exp TOK_GE exp            {$$ = $2->adopt($1, $3);}
            | exp '+' exp               {$$ = $2->adopt($1, $3);}
            | exp '-' exp               {$$ = $2->adopt($1, $3);}
            | exp '*' exp               {$$ = $2->adopt($1, $3);}
            | exp '/' exp               {$$ = $2->adopt($1, $3);}
            | exp '=' exp               {$$ = $2->adopt($1, $3);}
            ;

unop        : TOK_POS exp           {$$ = $$->adopt($2);}
            | TOK_NEG exp           {$$ = $$->adopt($2);}
            | '!' exp               {$$ = $$->adopt($2);}
            ;

allocator   : TOK_NEW TOK_IDENT '(' ')'
                {
                    destroy($3, $4);
                    $2 = $2->changeSym(TOK_TYPEID, $2);
                    $$ = $1->adopt($2);
                }
            | TOK_NEW TOK_STRING '(' exp ')'
                {
                    destroy($3, $5);
                    $1 = $1->changeSym(TOK_NEWSTRING,$1);
                    $$ = $1->adopt($4);
                }
            | TOK_NEW basetype '[' exp ']'
                {
                    destroy($3, $5);
                    $1 = $1->changeSym(TOK_NEWARRAY, $1);
                    $$ = $1->adopt($2, $4);
                }
            ;

cexp        : TOK_IDENT '(' exp
                {
                    $2 = $2->changeSym(TOK_CALL, $2);
                    $$ = $2->adopt($1, $3);
                }
            | cexp ',' exp
                {
                    destroy($2);
                    $$ = $1->adopt($3);
                }
            ;

call        : cexp ')'
                {
                    destroy($2);
                    $$ = $1;
                }
            | TOK_IDENT '(' ')'
                {
                    destroy($3);
                    $2 = $2->changeSym(TOK_CALL, $2);
                    $$ = $2->adopt($1);
                }
            ;

variable         : TOK_IDENT         {$$ = $1;}
            | exp '[' exp ']'  
                { 
                    destroy($4);
                    $2 = $2->changeSym(TOK_INDEX, $2);
                    $$ = $2->adopt($1, $3);
                }
            | exp '.' TOK_IDENT 
                {
                    $3 = $3->changeSym(TOK_FIELD, $3);
                    $$ = $2->adopt($1, $3);
                }
            ;

constant    : TOK_INTCON            {$$ = $1;}
            | TOK_CHARCON           {$$ = $1;}
            | TOK_STRINGCON         {$$ = $1;}
            | TOK_NULL              {$$ = $1;}
            ;

%%

const char *parser::get_tname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}

const char *get_yytname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}


bool is_defined_token(int symbol) {
   return YYTRANSLATE(symbol) > YYUNDEFTOK;
}
