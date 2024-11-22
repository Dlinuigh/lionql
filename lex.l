%{
  #include "parser.tab.h"
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

("PRIMARY +KEY"|"primary +key") {yylval.str = strdup(yytext);return PRIMARY_KEY;}
("DEFAULT"|"default") {return DEFAULT;}

("INT"|"int") {return INT;}
("TINYINT"|"tinyint") {return TINYINT;}
("SMALLINT"|"smallint") {return SMALLINT;}
("BIGINT"|"bigint") {return BIGINT;}
("DECIMAL("|"decimal(") {return DECIMAL_TYPE;}
("NUMERIC("|"numeric(") {return NUMERIC;}
("FLOAT"|"float") {return FLOAT;}
("DOUBLE"|"double") {return DOUBLE;}
[1-9][0-9] {return DECIMAL_PRECISION;}
[0-9]{0,2} {return DECIMAL_SCALE;}

[1-9][0-9]{0,2} {return FIX_LEN;}
[1-9][0-9]{0,4} {return VAR_LEN;}
("CHAR("|"char(") {return CHAR;}
("VARCHAR("|"varchar(") {return VARCHAR;}
("TEXT"|"text") {return TEXT;}

("DATE"|"date") {return DATE;}
("TIME"|"time") {return TIME;}
("DATETIME"|"datetime") {return DATETIME;}
("YEAR"|"year") {return YEAR;}
("TIMESTAMP"|"timestamp") {return TIMESTAMP;}
("CURRENT_TIMESTAMP"|"current_timestamp") {return CURRENT_TIMESTAMP;}

("BOOL"|"bool") {return BOOL;}
("BLOB"|"blob") {return BLOB;}
("BINARY("|"binary(") {return BINARY_TYPE;}
("VARBINARY("|"varbinary(") {return VARBINARY;}

("ENUM"|"enum") {return ENUM;}
("SET("|"set(") {return SET_FUNC;}
("UUID"|"uuid") {return UUID;}
("JSON"|"json") {return JSON;}
("XML"|"xml") {return XML;}

("INNER"|"inner") {return INNER;}
("LEFT"|"left") {return LEFT;}
("JOIN"|"join") {return JOIN;}
("ORDER"|"order") {return ORDER;}
("BY"|"by") {return BY;}
("LIMIT"|"limit") {return LIMIT;}
("ASC"|"asc") {return ASC;}
("DESC"|"desc") {return DESC;}
("OFFSET"|"offset") {return OFFSET;}
("WITH"|"with") {return WITH;}
("IN"|"in") {return IN;}
("IS"|"is") {return IS;}
("NULL"|"null") {yylval.str = strdup(yytext);return NULL_VAL;}
("NOT +NULL"|"not +null") {yylval.str = strdup(yytext);return NOT_NULL_VAL;}
("NOT"|"not") {return NOT;}
"*" {return MATCH_ANY;}

("LEFT("|"left(") {return LEFT_FUNC;}
("AVG("|"avg(") {return AVG_FUNC;}

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
