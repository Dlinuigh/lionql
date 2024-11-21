%{
  #include "parser.tab.h"
%}
%x SET_MODE
%%
("SELECT"|"select") {return SELECT;}
("DELETE"|"delete") {return DELETE;}
("INSERT"|"insert") {return INSERT;}
("UPDATE"|"update") {return UPDATE;}
("FROM"|"from") {return FROM;}
("WHERE"|"where") {return WHERE;}
("INTO"|"into") {return INTO;}
("VALUES"|"values") {return VALUES;}
("SET"|"set") {BEGIN(SET_MODE); return SET;}
"IS" {return IS;}
"NULL" {return NULL_VAL;}
"NOT" {return NOT;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext);return IDENTIFIER;}
"[a-zA-Z_][a-zA-Z0-9_]*" {yylval.str = strdup(yytext);return IDENTIFIER;}
(0x[0-9a-f]+|0x[0-9A-F]+) {yylval.str = strdup(yytext); return BINARY;}
[+-]?[0-9]+ {yylval.str = strdup(yytext); return INTEGER;}
[+-]?[0-9]+.[0-9]+ {yylval.str = strdup(yytext); return DECIMAL;}
[a-zA-Z0-9._-]* {yylval.str = strdup(yytext); return STRING;}
'[a-zA-Z0-9._-]*' {yylval.str = strdup(yytext); return STRING;}
">" {yylval.str = strdup(yytext); return GT;}
"<" {yylval.str = strdup(yytext); return LT;}
"=" {yylval.str = strdup(yytext); return EQ;}
">=" {yylval.str = strdup(yytext); return GE;}
"<=" {yylval.str = strdup(yytext); return LE;}
"," {return COMMA;}
"(" {return LPAREN;}
")" {return RPAREN;}
";" {return END;}
[ \t\n\r]+ {}
%%