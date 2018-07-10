/* $Id: lexer.l,v 1.7 2016-10-27 19:45:59-07 - - $ */

%{

#include "lyutils.h"
#include "yyparse.h"
#define YY_USER_ACTION  { lexer::advance(); }

int yylval_token (int symbol) {
   yylval = new astree (symbol, lexer::lloc, yytext);
   return symbol;
}

%}

%option 8bit
%option debug
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn
/*%option verbose*/

TOK_VOID      []
TOK_CHAR      [A-Za-z_]
TOK_INT       ([0-9]+)
TOK_STRING    ({TOK_CHAR}+)
TOK_IF        [>=]
TOK_ELSE      [>=]
TOK_WHILE     [>=]
TOK_RETURN    [>=]
TOK_STRUCT    [>=]
TOK_NULL      [>=]
TOK_NEW       [>=]
TOK_ARRAY     [>=]
TOK_EQ        [>=]
TOK_NE        [>=]
TOK_LT        [>=]
TOK_LE        [>=]      
TOK_GT        [=<]
TOK_GE        [>=]
TOK_IDENT     ({TOK_CHAR}({TOK_CHAR}|{TOK_INT})*)
TOK_INTCON    [>=]
TOK_CHARCON   [>=]
TOK_STRINGCON [>=]
TOK_BLOCK     [>=]
TOK_CALL      [>=]
TOK_IFELSE    [>=]
TOK_INITDECL  [>=]
TOK_POS       [>=]
TOK_NEG       [>=]
TOK_NEWARRAY  [>=]
TOK_TYPEID    [>=]
TOK_FIELD     [>=]
TOK_ORD       [>=]
TOK_CHR       [>=]
TOK_ROOT      [>=]

%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { lexer::newline(); }

{NUMBER}        { return yylval_token (NUMBER); }
{IDENT}         { return yylval_token (IDENT); }
"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"^"             { return yylval_token ('^'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
";"             { return yylval_token (';'); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"[]"            { return yylval_token ('[]'); }

{NOTNUMBER}     { lexer::badtoken (yytext);
                  return yylval_token (NUMBER); }
.               { lexer::badchar (*yytext); }

%%
