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
%token <str> IDENTIFIER
%token <str> STRING
%token <str> INTEGER
%token <str> DECIMAL
%token <str> BINARY
%token SELECT FROM WHERE
%token INSERT INTO VALUES
%token UPDATE SET
%token DELETE
%token CREATE DATABASE TABLE VIEW INDEX PRIMARY AS ON
%token ALTER ADD MODIFY RENAME COLUMN TO BETWEEN AND USING
%token DROP
%token INNER LEFT JOIN
%token ORDER BY LIMIT
%token ASC DESC OFFSET
%token IS NULL_VAL NOT END IN WITH MATCH_ANY
%token <str> GT LT EQ GE LE COMMA LPAREN RPAREN
%type <str> stmt select_stmt
%type <str> rvalue lvalue
%type <str> condition restrict restrict_list
%type <str> compare
%type <str> update
%type <str> values_list values_vector column_list update_list
%%
stmt_list:
  stmt_list stmt END {printf("%s ;\n", $2); free($2);}
  |;
stmt:
  select_stmt
  | INSERT INTO lvalue LPAREN column_list RPAREN VALUES values_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "INSERT INTO %s ( %s ) VALUES\n%s", $3, $5, $8);
    free($3);free($5);free($8);
    $$ = ptr;
  }
  | UPDATE lvalue SET update_list condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "UPDATE %s SET %s %s", $2, $4, $5);
    free($2);free($4);free($5);
    $$ = ptr;
  }
  | DELETE FROM lvalue condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELETE FROM %s %s", $3, $4);
    free($3);free($4);
    $$ = ptr;
  }
  | DELETE FROM lvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELETE FROM %s", $3);
    free($3);
    $$ = ptr;
  }
  | CREATE DATABASE IDENTIFIER {

  }
  | CREATE INDEX IDENTIFIER ON lvalue LPAREN IDENTIFIER RPAREN
  | ALTER TABLE lvalue RENAME COLUMN IDENTIFIER TO IDENTIFIER
  | ALTER TABLE lvalue DROP COLUMN IDENTIFIER
  | ALTER TABLE lvalue RENAME TO IDENTIFIER
  | DROP DATABASE IDENTIFIER
  | DROP TABLE IDENTIFIER
  | DROP VIEW IDENTIFIER
  | DROP INDEX IDENTIFIER
  ;
select_stmt:
  SELECT IDENTIFIER FROM LPAREN lvalue RPAREN condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM ( %s ) %s", $2, $5, $7);
    free($2);free($5);free($7);
    $$ = ptr;
  }
  | SELECT IDENTIFIER FROM lvalue condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM %s %s", $2, $4, $5);
    free($2);free($4);free($5);
    $$ = ptr;
  }
  ;
restrict_list:
  restrict_list restrict
  |;
restrict:
  WHERE condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s", $2);
    free($2);
    $$ = ptr;
  }
  | ORDER BY lvalue DESC{

  }
  | ORDER BY lvalue ASC{

  }
  | LIMIT rvalue {

  }
  | OFFSET rvalue {

  }
  ;
condition:
  lvalue compare rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | lvalue IS NULL_VAL {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s IS NULL", $1);
    free($1);
    $$ = ptr;
  }
  | lvalue IS NOT NULL_VAL {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s IS NOT NULL", $1);
    free($1);
    $$ = ptr;
  }
  ;
update_list:
  update_list COMMA update {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | update
  ;
update:
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
values_list:
  values_list COMMA LPAREN values_vector RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n( %s )", $1, $4);
    free($1);free($4);
    $$ = ptr;
  }
  | LPAREN values_vector RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "( %s )", $2);
    free($2);
    $$ = ptr;
  }
  ;
values_vector:
  values_vector COMMA rvalue {
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
  | select_stmt
  | lvalue INNER JOIN lvalue ON condition {

  }
  | lvalue LEFT JOIN lvalue ON condition {

  }
  ;
rvalue:
  INTEGER
  | DECIMAL
  | STRING
  | BINARY
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