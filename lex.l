%{
  #include "parser.tab.h"
%}
%%
("SELECT"|"select") {return SELECT;}
("DELETE"|"delete") {return DELETE;}
("INSERT"|"insert") {return INSERT;}
("UPDATE"|"update") {return UPDATE;}
("FROM"|"from") {return FROM;}
("WHERE"|"where") {return WHERE;}
("INTO"|"into") {return INTO;}
("VALUES"|"values") {return VALUES;}
("SET"|"set") {return SET;}
("CREATE"|"create") {return CREATE;}
("DATABASE"|"database") {return DATABASE;}
("TABLE"|"table") {return TABLE;}
("VIEW"|"view") {return VIEW;}
("INDEX"|"index") {return INDEX;}
("PRIMARY"|"primary") {return PRIMARY;}
("AS"|"as") {return AS;}
("ON"|"on") {return ON;}
("ALTER"|"alter") {return ALTER;}
("ADD"|"add") {return ADD;}
("MODIFY"|"modify") {return MODIFY;}
("RENAME"|"rename") {return RENAME;}
("COLUMN"|"column") {return COLUMN;}
("TO"|"to") {return TO;}
("DROP"|"drop") {return DROP;}
("INNER"|"inner") {return INNER;}
("LEFT"|"left") {return LEFT;}
("JOIN"|"join") {return JOIN;}
("ORDER"|"order") {return ORDER;}
("ASC"|"asc") {return ASC;}
("DESC"|"desc") {return DESC;}
("OFFSET"|"offset") {return OFFSET;}
"IS" {return IS;}
"NULL" {return NULL_VAL;}
"*" {return MATCH_ANY;}
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