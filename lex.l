%{
  #include "parser.tab.h"
  #include <time.h>
%}
%%
("SELECT"|"select") {return SELECT;}
("DELETE"|"delete") {return DELETE;}
("INSERT"|"insert") {return INSERT;}
("UPDATE"|"update") {return UPDATE;}
("CREATE"|"create") {return CREATE;}
("ALTER"|"alter") {return ALTER;}
("DROP"|"drop") {return DROP;}

("FROM"|"from") {return FROM;}
("WHERE"|"where") {return WHERE;}
("INTO"|"into") {return INTO;}
("AS"|"as") {return AS;}
("TO"|"to") {return TO;}
("BETWEEN"|"between") {return BETWEEN;}
("ADD"|"add") {return ADD;}
("USING"|"using") {return USING;}
("ON"|"on") {return ON;}
("VALUES"|"values") {return VALUES;}

("RENAME"|"rename") {return RENAME;}
("MODIFY"|"modify") {return MODIFY;}
("SET"|"set") {return SET;}

("DATABASE"|"database") {return DATABASE;}
("TABLE"|"table") {return TABLE;}
("VIEW"|"view") {return VIEW;}
("INDEX"|"index") {return INDEX;}
("COLUMN"|"column") {return COLUMN;}
("PROCEDURE"|"procedure") {return PROCEDURE;}
("TRIGGER"|"trigger") {return TRIGGER;}
("ROW"|"row") {return ROW;}
("DECLARE"|"declare") {return DECLARE;}

("PRIMARY"|"primary") {return PRIMARY;}
("DEFAULT"|"default") {return DEFAULT;}
("CHECK"|"check") {return CHECK;}
("AUTO_INCREMENT"|"auto_increment") {return AUTO_INCREMENT;}
("USE"|"use") {return USE;}
("FOREIGN"|"foreign") {return FOREIGN;}
("KEY"|"key") {return KEY;}
("REFERENCES"|"references") {return REFERENCES;}
("AFTER"|"after") {return AFTER;}
("BEFORE"|"before") {return BEFORE;}
("DELIMITER"|"delimiter") {return DELIMITER;}
("END[a-zA-Z0-9.]+"|"end[a-zA-Z0-9.]+") {return DELIMITER_END;}
("BEGIN"|"begin") {return BEGIN_SYM;}
("END"|"end") {return END_SYM;}
("CALL"|"call") {return CALL;}
("FOR"|"for") {return FOR;}
("EACH"|"each") {return EACH;}
("NOW()"|"now()") {time_t t = time(NULL); struct tm* current_time = localtime(&t); yylval.str = malloc(sizeof(char)*80);strftime(yylval.str, sizeof(char)*80, "%Y-%m-%d %H:%M:%S", current_time); return NOW;}
("AND"|"and") {return AND;}
("OR"|"or") {return OR;}
("IF"|"if") {return IF;}
("THEN"|"then") {return THEN;}
NEW.[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext);return NEW;}
OLD.[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext);return OLD;}

("INT"|"int") {yylval.str = strdup(yytext);return INT;}
("TINYINT"|"tinyint") {yylval.str = strdup(yytext);return TINYINT;}
("SMALLINT"|"smallint") {yylval.str = strdup(yytext);return SMALLINT;}
("BIGINT"|"bigint") {yylval.str = strdup(yytext);return BIGINT;}
("DECIMAL("|"decimal(") {yylval.str = strdup(yytext);return DECIMAL_TYPE;}
("NUMERIC("|"numeric(") {yylval.str = strdup(yytext);return NUMERIC;}
("FLOAT"|"float") {yylval.str = strdup(yytext);return FLOAT;}
("DOUBLE"|"double") {yylval.str = strdup(yytext);return DOUBLE;}

("CHAR("|"char(") {yylval.str = strdup(yytext);return CHAR;}
("VARCHAR("|"varchar(") {yylval.str = strdup(yytext);return VARCHAR;}
("TEXT"|"text") {yylval.str = strdup(yytext);return TEXT;}

("DATE"|"date") {yylval.str = strdup(yytext);return DATE;}
("TIME"|"time") {yylval.str = strdup(yytext);return TIME;}
("DATETIME"|"datetime") {yylval.str = strdup(yytext);return DATETIME;}
("YEAR"|"year") {yylval.str = strdup(yytext);return YEAR;}
("TIMESTAMP"|"timestamp") {yylval.str = strdup(yytext);return TIMESTAMP;}
("CURRENT_TIMESTAMP"|"current_timestamp") {yylval.str = strdup(yytext);return CURRENT_TIMESTAMP;}

("BOOL"|"bool") {yylval.str = strdup(yytext);return BOOL;}
("BLOB"|"blob") {yylval.str = strdup(yytext);return BLOB;}
("BINARY("|"binary(") {yylval.str = strdup(yytext);return BINARY_TYPE;}
("VARBINARY("|"varbinary(") {yylval.str = strdup(yytext);return VARBINARY;}

("ENUM"|"enum") {yylval.str = strdup(yytext);return ENUM;}
("SET("|"set(") {yylval.str = strdup(yytext);return SET_FUNC;}
("UUID"|"uuid") {yylval.str = strdup(yytext);return UUID;}
("JSON"|"json") {yylval.str = strdup(yytext);return JSON;}
("XML"|"xml") {yylval.str = strdup(yytext);return XML;}

("SIGNAL"|"signal") {return SIGNAL;}
("SQLSTATE"|"sqlstate") {return SQLSTATE;}
("MESSAGE_TEXT"|"message_text") {return MESSAGE_TEXT;}

("INNER"|"inner") {return INNER;}
("LEFT"|"left") {return LEFT;}
("JOIN"|"join") {return JOIN;}
("ORDER"|"order") {return ORDER;}
("GROUP"|"group") {return GROUP;}
("BY"|"by") {return BY;}
("LIMIT"|"limit") {return LIMIT;}
("ASC"|"asc") {return ASC;}
("DESC"|"desc") {return DESC;}
("OFFSET"|"offset") {return OFFSET;}
("WITH"|"with") {return WITH;}
("IS"|"is") {return IS;}
("NULL"|"null") {return NULL_VAL;}
("NOT"|"not") {return NOT;}
"*" {yylval.str = strdup(yytext); return MATCH_ANY;}
("IN"|"in") {yylval.str = strdup(yytext); return IN;}
("OUT"|"out") {yylval.str = strdup(yytext); return OUT;}
("INOUT"|"inout") {yylval.str = strdup(yytext); return INOUT;}

("LEFT("|"left(") {return LEFT_FUNC;}
("AVG("|"avg(") {return AVG_FUNC;}

[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext);return IDENTIFIER;}
"[a-zA-Z_][a-zA-Z0-9_]*" {yylval.str = strdup(yytext);return IDENTIFIER;}
[a-zA-Z_][a-zA-Z0-9_]*\.[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext);return A_IDENT;}
\@[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext); return G_IDENT;}
(0x[0-9a-f]+|0x[0-9A-F]+) {yylval.str = strdup(yytext); return BINARY;}
[+-]?[0-9]+ {yylval.str = strdup(yytext); return INTEGER;}
[+-]?[0-9]+.[0-9]+ {yylval.str = strdup(yytext); return DECIMAL;}
[a-zA-Z0-9._\-\$\\\/]+ {yylval.str = strdup(yytext); return STRING;}
'[a-zA-Z0-9._\-\$\\\/]+' {yylval.str = strdup(yytext); return STRING;}

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
