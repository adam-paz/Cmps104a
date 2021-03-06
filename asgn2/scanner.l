
%{

#include "lyutils.h"

#define YY_USER_ACTION  { lexer::advance(); }

#define RETURN(SYMBOL) { \
   yylval = new astree (SYMBOL, lexer::lloc, yytext); \
   fprintf(outfile_tok, "  %2zu %2zu.%03zu  %3d %-14s (%s)\n",\
              yylval->lloc.filenr,yylval->lloc.linenr,\
              yylval->lloc.offset, SYMBOL,\
              parser::get_tname(yylval->symbol), yytext);\
   return SYMBOL; \
}

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn

LETTER          [A-Za-z_]
DIGIT           [0-9]
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)

%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { }

char          { RETURN (TOK_CHAR); }
else          { RETURN (TOK_ELSE); }
if            { RETURN (TOK_IF); }
int           { RETURN (TOK_INT); }
new           { RETURN (TOK_NEW); }
null          { RETURN (TOK_NULL); }
return        { RETURN (TOK_RETURN); }
string        { RETURN (TOK_STRING); }
struct        { RETURN (TOK_STRUCT); }
void          { RETURN (TOK_VOID); }
while         { RETURN (TOK_WHILE); }

"="             { RETURN ('='); }
"+"             { RETURN ('+'); }
"-"             { RETURN ('-'); }
"*"             { RETURN ('*'); }
"/"             { RETURN ('/'); }
"("             { RETURN ('('); }
")"             { RETURN (')'); }
";"             { RETURN (';'); }
"!="            { RETURN (TOK_NE); }
"!"             { RETURN ('!'); }
"%"             { RETURN ('%'); }
"<="            { RETURN (TOK_LE); }
"<"             { RETURN (TOK_LT); }
"=="            { RETURN (TOK_EQ); }
">="            { RETURN (TOK_GE); }
">"             { RETURN (TOK_GT); }
"[]"            { RETURN (TOK_NEWARRAY); }
"["             { RETURN ('['); } 
"]"             { RETURN (']'); }
"{"             { RETURN ('{'); }
"}"             { RETURN ('}'); }
","             { RETURN (','); }
"."             { RETURN ('.'); }

{DIGIT}*        { RETURN (TOK_INTCON); }
('([^\\'\n]|\\[\\'"0nt])') { RETURN (TOK_CHARCON); }

(\"([^\\"\n]|\\[\\'"0nt])*\") { RETURN (TOK_STRINGCON); }

{IDENT}         { RETURN (TOK_IDENT); }

{NOTNUMBER}     { lexer::badtoken (yytext); }
.               { lexer::badchar (*yytext); }

%%

