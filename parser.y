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
%token SELECT
%token DELETE
%token INSERT
%token UPDATE
%token FROM
%token WHERE
%token INTO
%token VALUES
%token SET
%token IS
%token NULL_VAL
%token NOT
%token END
%token <str> GT LT EQ GE LE COMMA LPAREN RPAREN
%type <str> stmt
%type <str> rvalue
%type <str> condition
%type <str> compare
%type <str> update
%type <str> values_list values_vector column_list update_list
%%
stmt_list:
  stmt_list stmt END {printf("%s ;\n", $2); free($2);}
  |;
stmt:
  SELECT IDENTIFIER FROM LPAREN stmt RPAREN condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM ( %s ) %s", $2, $5, $7);
    free($2);free($5);free($7);
    $$ = ptr;
  }
  | SELECT IDENTIFIER FROM IDENTIFIER condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM %s %s", $2, $4, $5);
    free($2);free($4);free($5);
    $$ = ptr;
  }
  | INSERT INTO IDENTIFIER LPAREN column_list RPAREN VALUES values_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "INSERT INTO %s ( %s ) VALUES\n%s", $3, $5, $8);
    free($3);free($5);free($8);
    $$ = ptr;
  }
  | UPDATE IDENTIFIER SET update_list condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "UPDATE %s SET %s %s", $2, $4, $5);
    free($2);free($4);free($5);
    $$ = ptr;
  }
  | DELETE FROM IDENTIFIER condition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELETE FROM %s %s", $3, $4);
    free($3);free($4);
    $$ = ptr;
  }
  | DELETE FROM IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELETE FROM %s", $3);
    free($3);
    $$ = ptr;
  }
  ;
condition:
  WHERE IDENTIFIER compare rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s %s %s", $2, $3, $4);
    free($2);free($3);free($4);
    $$ = ptr;
  }
  | WHERE IDENTIFIER IS NULL_VAL {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s IS NULL", $2);
    free($2);
    $$ = ptr;
  }
  | WHERE IDENTIFIER IS NOT NULL_VAL {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s IS NOT NULL", $2);
    free($2);
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