%debug
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
struct Query{
  char* table;
  char* column;
  int value;
};
extern int yylex();
extern int yyparse();
extern int yydebug;
// extern void yy_scan_string(const char* str);
// extern void yylex_destroy();
extern FILE* yyin;
void yyerror(const char* s){
  fprintf(stderr, "Error: %s\n", s);
}
%}
%union {
  char* str;
  int num;
  int intval;      // 对应整数值
  double floatval; // 对应浮点值
  char* strval;    // 对应字符串值
  struct Query* query;
}
%token <str> IDENTIFIER
%token <str> STRING
%token <num> NUMBER
%token SELECT
%token DELETE
%token INSERT
%token UPDATE
%token FROM
%token WHERE
%type <query> Query
%%
Query:
  SELECT IDENTIFIER FROM IDENTIFIER WHERE IDENTIFIER '=' NUMBER ';' {printf("Parsed: SELECT %s FROM %s WHERE %s = %d\n", $2, $4, $6, $8);}
| SELECT IDENTIFIER FROM IDENTIFIER WHERE IDENTIFIER '>' NUMBER ';' {printf("Parsed: SELECT %s FROM %s WHERE %s > %d\n", $2, $4, $6, $8);}
| SELECT IDENTIFIER FROM IDENTIFIER WHERE IDENTIFIER '<' NUMBER ';' {printf("Parsed: SELECT %s FROM %s WHERE %s < %d\n", $2, $4, $6, $8);}
;
%%
int main(int argc, char* argv[]){
  yydebug = (int)atoi(argv[1]);
  yyin = fopen("query.sql", "r");
  if (!yyin) {
      fprintf(stderr, "Failed to open file\n");
      return 1;
  }
  /* yy_scan_string(argv[1]); */
  yyparse();
  /* yylex_destroy(); */
  return 0;
}