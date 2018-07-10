
%{

#include "lyutils.h"
#include "string_set.h"

#define YY_USER_ACTION  { lexer::advance(); }

int yylval_token (int symbol) {
   yylval = new astree (symbol, lexer::lloc, yytext);
   fprintf(outfile_tok, "%2zu %2zu.%03zu   %3d %-14s (%s)\n",\
              yylval->lloc.filenr,yylval->lloc.linenr,\
              yylval->lloc.offset, symbol,\
              parser::get_tname(yylval->symbol), yytext);
   const string* token = string_set::intern(yytext);
   (void) token;
   return symbol;
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

char          { return yylval_token(TOK_CHAR); }
else          { return yylval_token(TOK_ELSE); }
if            { return yylval_token(TOK_IF); }
int           { return yylval_token(TOK_INT); }
new           { return yylval_token(TOK_NEW); }
null          { return yylval_token(TOK_NULL); }
return        { return yylval_token(TOK_RETURN); }
string        { return yylval_token(TOK_STRING); }
struct        { return yylval_token(TOK_STRUCT); }
void          { return yylval_token(TOK_VOID); }
while         { return yylval_token(TOK_WHILE); }

"="             { return yylval_token('='); }
"+"             { return yylval_token('+'); }
"-"             { return yylval_token('-'); }
"*"             { return yylval_token('*'); }
"/"             { return yylval_token('/'); }
"("             { return yylval_token('('); }
")"             { return yylval_token(')'); }
";"             { return yylval_token(';'); }
"!="            { return yylval_token(TOK_NE); }
"!"             { return yylval_token('!'); }
"%"             { return yylval_token('%'); }
"<="            { return yylval_token(TOK_LE); }
"<"             { return yylval_token(TOK_LT); }
"=="            { return yylval_token(TOK_EQ); }
">="            { return yylval_token(TOK_GE); }
">"             { return yylval_token(TOK_GT); }
"[]"            { return yylval_token(TOK_NEWARRAY); }
"["             { return yylval_token('['); } 
"]"             { return yylval_token(']'); }
"{"             { return yylval_token('{'); }
"}"             { return yylval_token('}'); }
","             { return yylval_token(','); }
"."             { return yylval_token('.'); }

{DIGIT}*        { return (TOK_INTCON); }
('([^\\'\n]|\\[\\'"0nt])') { return (TOK_CHARCON); }

(\"([^\\"\n]|\\[\\'"0nt])*\") { return (TOK_STRINGCON); }

{IDENT}         { return (TOK_IDENT); }

{NOTNUMBER}     { lexer::badtoken (yytext); }
.               { lexer::badchar (*yytext); }

%%

