%debug
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
extern int yylex();
extern int yyparse();
extern int yydebug;
extern FILE* yyin;
void yyerror(const char* s){
  fprintf(stderr, "Error: %s\n", s);
}
%}
%union {
  char* str;
}
%token <str> INTEGER DECIMAL BINARY STRING IDENTIFIER // variable term
%token SELECT INSERT UPDATE DELETE CREATE ALTER DROP // SQL operator
%token FROM WHERE INTO AS TO BETWEEN ADD USING ON VALUES // auxilary token
%token RENAME MODIFY SET // declare operate word
%token <str> NULL_VAL NOT_NULL_VAL PRIMARY_KEY DEFAULT
%token <str> DECIMAL_PRECISION DECIMAL_SCALE FIX_LEN VAR_LEN AUTO_INCREMENT
%token <str> INT TINYINT SMALLINT BIGINT DECIMAL_TYPE NUMERIC FLOAT DOUBLE
%token <str> CHAR VARCHAR TEXT 
%token <str> DATE TIME DATETIME YEAR TIMESTAMP CURRENT_TIMESTAMP
%token <str> BOOL BLOB BINARY_TYPE VARBINARY 
%token <str> ENUM SET_FUNC UUID JSON XML // basic data type
%token INNER LEFT JOIN ORDER BY LIMIT ASC DESC OFFSET WITH IN
%token DATABASE TABLE VIEW INDEX COLUMN // struct type
%token IS AND OR NOT END MATCH_ANY 
%token LEFT_FUNC AVG_FUNC
%token <str> GT LT EQ GE LE COMMA LPAREN RPAREN

%type <str> stmt select_stmt insert_stmt update_stmt delete_stmt create_stmt alter_stmt drop_stmt
%type <str> stmt_list column_list value_list value_list_list assign_list member_list
%type <str> condition lvalue rvalue assign compare restrict primary member
%type <str> where_cond order_cond where_order_cond
%type <str> select_base update_base delete_base
%type <str> type type_addition
%%
stmt_list:
  stmt_list stmt END {printf("%s ;\n", $2); free($2);}
  | stmt END {printf("%s ;\n", $1); free($1);}
;
stmt:
  select_stmt | insert_stmt | update_stmt | delete_stmt | create_stmt | alter_stmt | drop_stmt ;
select_stmt:
  select_base condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | select_base where_order_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | select_base
;
select_base:
  SELECT IDENTIFIER FROM LPAREN select_base RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM ( %s ) %s", $2, $5);
    free($2);free($5);
    $$ = ptr;
  }
  | SELECT IDENTIFIER FROM lvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM %s %s", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
;
insert_stmt:
  INSERT INTO lvalue LPAREN column_list RPAREN VALUES value_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "INSERT INTO %s ( %s ) VALUES\n%s", $3, $5, $8);
    free($3);free($5);free($8);
    $$ = ptr;
  }
;
update_stmt:
  update_base condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | update_base where_order_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | update_base
;
update_base:
  UPDATE lvalue SET assign_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "UPDATE %s SET %s", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
;
delete_stmt:
  delete_base condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | delete_base where_order_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | delete_base
  ;
delete_base:
  DELETE FROM lvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELETE FROM %s", $3);
    free($3);
    $$ = ptr;
  }
;
create_stmt:
  CREATE DATABASE IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE DATABASE %s", $3);
    free($3);
    $$ = ptr;
  }
  | CREATE TABLE IDENTIFIER LPAREN member_list RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE DATABASE %s ( %s )", $3, $5);
    free($3);free($5);
    $$ = ptr;
  }
  | CREATE TABLE IDENTIFIER LPAREN member_list COMMA primary RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE DATABASE %s ( %s )", $3, $5);
    free($3);free($5);
    $$ = ptr;
  }
  | CREATE INDEX IDENTIFIER ON lvalue LPAREN IDENTIFIER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE INDEX %s ON %s ( %s )", $3, $5, $7);
    free($3);free($5);free($7);
    $$ = ptr;
  }
;
alter_stmt:
  ALTER TABLE lvalue RENAME COLUMN IDENTIFIER TO IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TABLE %s RENAME COLUMN %s TO %s", $3, $6, $8);
    free($3);free($6);free($8);
    $$ = ptr;
  }
  | ALTER TABLE lvalue DROP COLUMN IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TABLE %s DROP COLUMN %s", $3, $6);
    free($3);free($6);
    $$ = ptr;
  }
  | ALTER TABLE lvalue RENAME TO IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TABLE %s RENAME TO %s", $3, $6);
    free($3);free($6);
    $$ = ptr;
  }
;
drop_stmt:
  DROP DATABASE IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP DATABASE %s", $3);
    free($3);
    $$ = ptr;
  }
  | DROP TABLE IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP TABLE %s", $3);
    free($3);
    $$ = ptr;
  }
  | DROP VIEW IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP VIEW %s", $3);
    free($3);
    $$ = ptr;
  }
  | DROP INDEX IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DROP INDEX %s", $3);
    free($3);
    $$ = ptr;
  }
;
condition:
  where_cond | order_cond
;
where_order_cond:
  where_cond order_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
;
where_cond:
  WHERE lvalue compare rvalue restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s %s %s", $2, $3, $4);
    free($2);free($3);free($4);
    $$ = ptr;
  }
  | WHERE lvalue IS NULL_VAL restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s IS NULL", $2);
    free($2);
    $$ = ptr;
  }
  | WHERE lvalue IS NOT NULL_VAL restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s IS NOT NULL", $2);
    free($2);
    $$ = ptr;
  }
;
order_cond:
  ORDER BY lvalue DESC restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ORDER BY %s DESC %s", $3, $5);
    free($3);free($5);
    $$ = ptr;
  }
  | ORDER BY lvalue ASC restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ORDER BY %s ASC %s", $3, $5);
    free($3);free($5);
    $$ = ptr;
  }
;
restrict:
  LIMIT rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "LIMIT %s", $2);
    free($2);
    $$ = ptr;
  }
  | LIMIT rvalue OFFSET rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "LIMIT %s OFFSET %s", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
  | OFFSET rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "OFFSET %s", $2);
    free($2);
    $$ = ptr;
  }
  |{}
;
primary:
  PRIMARY_KEY LPAREN IDENTIFIER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
;
member_list:
  member_list COMMA member {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, ", %s", $3);
    free($3);
    $$ = ptr;
  }
  | member
;
member:
  IDENTIFIER type {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | IDENTIFIER type type_addition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
;
type:
  INT | TINYINT | SMALLINT | DECIMAL_TYPE | NUMERIC | FLOAT | DOUBLE |
  CHAR | VARCHAR | TEXT |
  DATE | TIME | DATETIME | YEAR | TIMESTAMP |
  BLOB | BINARY_TYPE | VARBINARY |
  ENUM | SET_FUNC | JSON | XML
;
type_addition:
  PRIMARY_KEY
  | NULL_VAL
  | NOT_NULL_VAL
  | DEFAULT rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s", $2);
    free($2);
    $$ = ptr;
  }
  | AUTO_INCREMENT
;
assign_list:
  assign_list COMMA assign {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | assign
;
assign:
  IDENTIFIER EQ rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " %s = %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
;
column_list:
  column_list COMMA IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | IDENTIFIER
;
value_list:
  value_list COMMA LPAREN value_list_list RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n( %s )", $1, $4);
    free($1);free($4);
    $$ = ptr;
  }
  | LPAREN value_list_list RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "( %s )", $2);
    free($2);
    $$ = ptr;
  }
;
value_list_list:
  value_list_list COMMA rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | rvalue
;
compare:
  GT | LT | EQ | GE | LE ;
lvalue:
  IDENTIFIER
  | lvalue INNER JOIN lvalue ON condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s INNER JOIN %s ON %s", $1, $4, $6);
    free($1);free($4);free($6);
    $$ = ptr;
  }
  | lvalue LEFT JOIN lvalue ON condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s LEFT JOIN %s ON %s", $1, $4, $6);
    free($1);free($4);free($6);
    $$ = ptr;
  }
;
rvalue:
  INTEGER
  | DECIMAL
  | STRING
  | BINARY
  | CURRENT_TIMESTAMP
;
%%
int main(int argc, char* argv[]){
  if(argc == 2){
    yydebug = (int)atoi(argv[1]);
  yyin = fopen("query.sql", "r");
  if (!yyin) {
      fprintf(stderr, "Failed to open file\n");
      return -1;
  }
  yyparse();
  }
  return 0;
}
