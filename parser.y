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
%token <str> INTEGER DECIMAL BINARY STRING IDENTIFIER A_IDENT G_IDENT// variable term
%token USE SELECT INSERT UPDATE DELETE CREATE ALTER DROP // SQL operator
%token FROM WHERE INTO AS TO BETWEEN ADD USING ON VALUES // auxilary token
%token RENAME MODIFY SET // declare operate word
%token NULL_VAL PRIMARY KEY DEFAULT AUTO_INCREMENT
%token FOREIGN AFTER BEFORE BEGIN_SYM END_SYM REFERENCES
%token <str> INT TINYINT SMALLINT BIGINT DECIMAL_TYPE NUMERIC FLOAT DOUBLE
%token <str> CHAR VARCHAR TEXT 
%token <str> DATE TIME DATETIME YEAR TIMESTAMP CURRENT_TIMESTAMP
%token <str> BOOL BLOB BINARY_TYPE VARBINARY 
%token <str> ENUM SET_FUNC UUID JSON XML // basic data type
%token <str> IN OUT INOUT
%token INNER LEFT JOIN ORDER BY LIMIT ASC DESC OFFSET WITH
%token DELIMITER CALL FOR EACH CHECK GROUP ROW DECLARE
%token DATABASE TABLE VIEW INDEX COLUMN PROCEDURE TRIGGER// struct type
%token IS AND OR NOT END 
%token LEFT_FUNC AVG_FUNC IF THEN SIGNAL MESSAGE_TEXT SQLSTATE DELIMITER_END
%token <str> GT LT EQ GE LE COMMA LPAREN RPAREN MATCH_ANY NEW OLD NOW

%type <str> stmt use_stmt select_stmt insert_stmt update_stmt delete_stmt 
%type <str> create_stmt alter_stmt drop_stmt procedure_stmt trigger_stmt
%type <str> stmt_list column_list lvalue value_list value_list_list
%type <str> assign_list member_list argument_list type_addition_list
%type <str> condition table rvalue assign compare restrict key_opt member
%type <str> where_cond order_cond combine_cond group_cond
%type <str> select_base update_base delete_base
%type <str> type type_addition argument argument_type func_stmt 
%type <str> expr condition_list logical call_stmt proc_stmt_list trig_stmt_list
%type <str> define_stmt trigger_time trigger_act
%type <str> if_stmt if_cond if_body
%type <str> signal_stmt
%%
stmt_list:
  stmt_list stmt END {printf("%s;\n", $2); free($2);}
  | stmt END {printf("%s;\n", $1); free($1);}
;
stmt:
  use_stmt | select_stmt | insert_stmt |
  update_stmt | delete_stmt | create_stmt |
  alter_stmt | drop_stmt | call_stmt |
  procedure_stmt | trigger_stmt | define_stmt
;
define_stmt:
  SET assign END {
  }
  | SELECT G_IDENT END {
  }
;
use_stmt:
  USE IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "USE %s", $2);
    free($2);
    $$ = ptr;
  }
;
call_stmt:
  CALL IDENTIFIER LPAREN value_list_list RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CALL %s(%s)", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
;
select_stmt:
  select_base condition restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | select_base combine_cond restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | select_base restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
;
select_base:
  SELECT column_list FROM LPAREN select_base RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM (%s)", $2, $5);
    free($2);free($5);
    $$ = ptr;
  }
  | SELECT column_list FROM table {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s FROM %s", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
;
insert_stmt:
  INSERT INTO table LPAREN column_list RPAREN VALUES value_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "INSERT INTO %s (%s) VALUES\n%s", $3, $5, $8);
    free($3);free($5);free($8);
    $$ = ptr;
  }
;
update_stmt:
  update_base condition restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s%s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | update_base combine_cond restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s%s", $1, $2);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | update_base restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
;
update_base:
  UPDATE table SET assign_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "UPDATE %s SET %s", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
;
delete_stmt:
  delete_base condition restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | delete_base combine_cond restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s%s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | delete_base restrict {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  ;
delete_base:
  DELETE FROM table {
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
    sprintf(ptr, "CREATE TABLE %s (\n%s\n)", $3, $5);
    free($3);free($5);
    $$ = ptr;
  }
  | CREATE TABLE IDENTIFIER LPAREN member_list COMMA key_opt RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TABLE %s (\n%s,\n%s\n)", $3, $5, $7);
    free($3);free($5);free($7);
    $$ = ptr;
  }
  | CREATE INDEX IDENTIFIER ON table LPAREN column_list RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE INDEX %s ON %s ( %s )", $3, $5, $7);
    free($3);free($5);free($7);
    $$ = ptr;
  }
  | CREATE VIEW IDENTIFIER AS select_stmt {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE VIEW %s AS\n%s", $3, $5);
    free($3);free($5);
    $$ = ptr;
  }
  | CREATE VIEW IDENTIFIER AS IDENTIFIER select_stmt {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE VIEW %s AS %s\n%s", $3, $5, $6);
    free($3);free($5);free($6);
    $$ = ptr;
  }
;
alter_stmt:
  ALTER TABLE table RENAME COLUMN IDENTIFIER TO IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ALTER TABLE %s RENAME COLUMN %s TO %s", $3, $6, $8);
    free($3);free($6);free($8);
    $$ = ptr;
  }
  | ALTER TABLE table DROP COLUMN IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ALTER TABLE %s DROP COLUMN %s", $3, $6);
    free($3);free($6);
    $$ = ptr;
  }
  | ALTER TABLE table RENAME TO IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ALTER TABLE %s RENAME TO %s", $3, $6);
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
procedure_stmt:
  CREATE PROCEDURE IDENTIFIER LPAREN argument_list RPAREN BEGIN_SYM proc_stmt_list END_SYM {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE PROCEDURE %s(\n%s\n)BEGIN\n%s\nEND", $3, $5, $8);
    free($3);free($5);free($8);
    $$ = ptr;
  }
  | DELIMITER STRING CREATE PROCEDURE IDENTIFIER LPAREN argument_list RPAREN BEGIN_SYM proc_stmt_list DELIMITER_END DELIMITER{
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE PROCEDURE %s(\n%s\n)BEGIN\n%s\nEND%s\nDELIMITER", $2, $5, $7, $10, $2);
    free($2);free($5);free($7);free($10);
    $$ = ptr;
  }
  | DELIMITER STRING CREATE PROCEDURE IDENTIFIER LPAREN argument_list RPAREN BEGIN_SYM proc_stmt_list END_SYM STRING DELIMITER{
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE PROCEDURE %s(\n%s\n)BEGIN\n%s\nEND %s\nDELIMITER", $2, $5, $7, $10, $12);
    free($2);free($5);free($7);free($10);free($12);
    $$ = ptr;
  }
;
proc_stmt_list:
  proc_stmt_list func_stmt {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s;", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | func_stmt
;
func_stmt:
  SET assign END {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SET %s;", $2);
    free($2);
    $$ = ptr;
  }
  | DECLARE member END {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DECLARE %s;", $2);
    free($2);
    $$ = ptr;
  }
  | SELECT IDENTIFIER END {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SELECT %s;", $2);
    free($2);
    $$ = ptr;
  }
  | if_stmt
  | call_stmt END
  | select_stmt END
  | insert_stmt END
  | delete_stmt END
;
if_stmt:
  IF if_cond THEN if_body END_SYM IF END {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "IF %s THEN\n%sEND IF;", $2);
    free($2);
    $$ = ptr;
  }
;
if_cond:
  NEW compare rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
;
if_body:
  signal_stmt END
  | insert_stmt END
  | update_stmt END
  | delete_stmt END
  | SET lvalue EQ rvalue END {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SET %s = %s;", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
;
signal_stmt:
  SIGNAL SQLSTATE STRING SET MESSAGE_TEXT EQ STRING END {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "SIGNAL SQLSTATE %s\nSET MESSAGE_TEXT = %s;", $3, $7);
    free($3);free($7);
    $$ = ptr;
  }
;
trigger_stmt:
  CREATE TRIGGER IDENTIFIER trigger_time trigger_act ON IDENTIFIER FOR EACH ROW BEGIN_SYM trig_stmt_list END_SYM {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CREATE TRIGGER %s\n%s %s ON %s\nFOR EACH ROW\nBEGIN\n%sEND%s", $3, $4, $5, $7, $12);
    free($3);free($4);free($5);free($7);free($12);
    $$ = ptr;
  }
  | DELIMITER STRING CREATE TRIGGER IDENTIFIER trigger_time trigger_act ON IDENTIFIER FOR EACH ROW BEGIN_SYM trig_stmt_list DELIMITER_END DELIMITER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE TRIGGER %s\n%s %s ON %s\nFOR EACH ROW\nBEGIN\n%sEND%s\nDELIMITER", $2, $5, $6, $7, $9, $14, $2);
    free($2);free($5);free($6);free($7);free($9);free($14);
    $$ = ptr;
  }
  | DELIMITER STRING CREATE TRIGGER IDENTIFIER trigger_time trigger_act ON IDENTIFIER FOR EACH ROW BEGIN_SYM trig_stmt_list END_SYM STRING DELIMITER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DELIMITER %s\nCREATE TRIGGER %s\n%s %s ON %s\nFOR EACH ROW\nBEGIN\n%sEND %s\nDELIMITER", $2, $5, $6, $7, $9, $14, $16);
    free($2);free($5);free($6);free($7);free($9);free($14);
    $$ = ptr;
  }
;
trig_stmt_list:
  trig_stmt_list func_stmt {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s;", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | func_stmt
;
trigger_time:
  BEFORE {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "BEFORE");
    $$ = ptr;
  }
  | AFTER {
    char* ptr = malloc(sizeof(char)*5);
    sprintf(ptr, "AFTER");
    $$ = ptr;
  }
;
trigger_act:
  INSERT {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "INSERT");
    $$ = ptr;
  }
  | UPDATE {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "UPDATE");
    $$ = ptr;
  }
  | DELETE {
    char* ptr = malloc(sizeof(char)*6);
    sprintf(ptr, "DELETE");
    $$ = ptr;
  }
;
condition:
  where_cond | order_cond | group_cond 
;
combine_cond:
  where_cond order_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | group_cond order_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | where_cond group_cond {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
;
where_cond:
  WHERE condition_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "WHERE %s", $2);
    free($2);
    $$ = ptr;
  }
;
group_cond:
  GROUP BY lvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "GROUP BY%s", $3);
    free($3);
    $$ = ptr;
  }
;
order_cond:
  ORDER BY lvalue DESC {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ORDER BY %s DESC", $3);
    free($3);
    $$ = ptr;
  }
  | ORDER BY lvalue ASC {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "ORDER BY %s ASC", $3);
    free($3);
    $$ = ptr;
  }
;
condition_list:
  condition_list AND logical {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s AND %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | condition_list OR logical {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s OR %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | logical
;
logical:
  lvalue compare lvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | lvalue compare rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
;
restrict:
  LIMIT rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " LIMIT %s", $2);
    free($2);
    $$ = ptr;
  }
  | LIMIT rvalue OFFSET rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " LIMIT %s OFFSET %s", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
  | OFFSET rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, " OFFSET %s", $2);
    free($2);
    $$ = ptr;
  }
  | {
    char* ptr = malloc(sizeof(char));
    sprintf(ptr, "");
    $$ = ptr;
  }
;
key_opt:
  PRIMARY KEY LPAREN IDENTIFIER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "PRIMARY KEY( %s )", $4);
    free($4);
    $$ = ptr;
  }
  | FOREIGN KEY LPAREN column_list RPAREN REFERENCES IDENTIFIER LPAREN column_list RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "FOREIGN KEY (%s) REFERENCES %s (%s)", $4, $7, $9);
    free($4);free($7);free($9);
    $$ = ptr;
  }
;
member_list:
  member_list COMMA member {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n%s", $1, $3);
    free($1);free($3);
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
  | IDENTIFIER type type_addition_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
;
argument_list:
  argument_list COMMA argument {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s,\n%s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | argument
;
argument:
  argument_type IDENTIFIER type {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s", $1, $2, $3);
    free($1);free($2);free($3);
    $$ = ptr;
  }
  | argument_type IDENTIFIER type type_addition_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s %s %s", $1, $2, $3, $4);
    free($1);free($2);free($3);free($4);
    $$ = ptr;
  }
;
argument_type:
  IN | OUT | INOUT ;
type:
  INT | TINYINT | SMALLINT |
  DECIMAL_TYPE INTEGER COMMA INTEGER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DECIMAL(%s, %s)", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
  | NUMERIC INTEGER COMMA INTEGER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "NUMERIC(%s, %s)", $2, $4);
    free($2);free($4);
    $$ = ptr;
  }
  | FLOAT | DOUBLE |
  CHAR INTEGER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "CHAR(%s)", $2);
    free($2);
    $$ = ptr;
  }
  | VARCHAR INTEGER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "VARCHAR(%s)", $2);
    free($2);
    $$ = ptr;
  }
  | TEXT | DATE | TIME | DATETIME | YEAR | TIMESTAMP | BLOB
  | BINARY_TYPE INTEGER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "BINARY(%s)", $2);
    free($2);
    $$ = ptr;
  }
  | VARBINARY INTEGER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "VARBINARY(%s)", $2);
    free($2);
    $$ = ptr;
  }
  | ENUM | SET_FUNC | JSON | XML
;
type_addition_list:
  type_addition_list type_addition {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
  | type_addition
;
type_addition:
  PRIMARY KEY {
    char* ptr = malloc(sizeof(char)*7);
    sprintf(ptr, "PRIMARY KEY");
    $$ = ptr;
  }
  | NULL_VAL {
    char* ptr = malloc(sizeof(char)*4);
    sprintf(ptr, "NULL");
    $$ = ptr;
  }
  | NOT NULL_VAL {
    char* ptr = malloc(sizeof(char)*8);
    sprintf(ptr, "NOT NULL");
    $$ = ptr;
  }
  | DEFAULT rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "DEFAULT %s", $2);
    free($2);
    $$ = ptr;
  }
  | AUTO_INCREMENT {
    char* ptr = malloc(sizeof(char)*14);
    sprintf(ptr, "AUTO_INCREMENT");
    $$ = ptr;
  }
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
  lvalue EQ expr {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | lvalue EQ LPAREN select_stmt RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = (%s)", $1, $4);
    free($1);free($4);
    $$ = ptr;
  }
  | NEW EQ expr {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | NEW EQ LPAREN select_stmt RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s = (%s)", $1, $4);
    free($1);free($4);
    $$ = ptr;
  }
;
column_list:
  column_list COMMA lvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s, %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | lvalue
;
lvalue:
  IDENTIFIER
  | IDENTIFIER AS IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s AS %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | MATCH_ANY
  | A_IDENT
  | G_IDENT
  | AVG_FUNC IDENTIFIER RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s)", $2);
    free($2);
    $$ = ptr;
  }
  | AVG_FUNC A_IDENT RPAREN {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s)", $2);
    free($2);
    $$ = ptr;
  }
  | AVG_FUNC IDENTIFIER RPAREN AS IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s) AS %s", $2, $5);
    free($2);free($5);
    $$ = ptr;
  }
  | AVG_FUNC A_IDENT RPAREN AS IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "AVG(%s) AS %s", $2, $5);
    free($2);free($5);
    $$ = ptr;
  }
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
  GT | LT | EQ | GE | LE 
  | IS {
    char* ptr = malloc(sizeof(char)*2);
    sprintf(ptr, "IS");
    $$ = ptr;
  }
;
table:
  IDENTIFIER
  | table INNER JOIN table ON condition_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s INNER JOIN %s ON %s", $1, $4, $6);
    free($1);free($4);free($6);
    $$ = ptr;
  }
  | table LEFT JOIN table ON condition_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s LEFT JOIN %s ON %s", $1, $4, $6);
    free($1);free($4);free($6);
    $$ = ptr;
  }
  | table JOIN table ON condition_list {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s JOIN %s ON %s", $1, $3, $5);
    free($1);free($3);free($5);
    $$ = ptr;
  }
  | IDENTIFIER IDENTIFIER {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s %s", $1, $2);
    free($1);free($2);
    $$ = ptr;
  }
;
rvalue:
  INTEGER
  | DECIMAL
  | STRING
  | BINARY
  | CURRENT_TIMESTAMP
  | NOW
  | NULL_VAL {
    char* ptr = malloc(sizeof(char)*4);
    sprintf(ptr, "NULL");
    $$ = ptr;
  }
  | NOT NULL_VAL {
    char* ptr = malloc(sizeof(char)*8);
    sprintf(ptr, "NOT NULL");
    $$ = ptr;
  }
  | NEW
;
expr:
  IDENTIFIER
  | rvalue
  | expr '+' rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | expr MATCH_ANY rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | expr '/' rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
  | expr '-' rvalue {
    char* ptr = malloc(sizeof(char)*512);
    sprintf(ptr, "%s + %s", $1, $3);
    free($1);free($3);
    $$ = ptr;
  }
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
    fclose(yyin);
  }
  return 0;
}
