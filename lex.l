%{
  #include "parser.tab.h"
%}
%%
("SELECT"|"select") {return SELECT;} //左边是正则表达式，右边是C语句
\"[a-zA-Z.]+\" {return STRING;}
("DELETE"|"delete") {return DELETE;}
("INSERT"|"insert") {return INSERT;}
("UPDATE"|"update") {return UPDATE;}
("FROM"|"from") {return FROM;}
("WHERE"|"where") {return WHERE;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.strval = strdup(yytext); return IDENTIFIER;}
[0-9]+ {yylval.intval = atoi(yytext); return NUMBER;}
"=" {return '=';}
";" {return ';';}
[ \t\n\r]+ {}
%%