sql: parser.tab.c lex.yy.c
	cc -o $@ parser.tab.c lex.yy.c -lfl
debug: parser.tab.c lex.yy.c
	cc -DYYDEBUG=1 -o sql parser.tab.c lex.yy.c -lfl
parser.tab.c: parser.y
	bison -o parser.tab.c -d parser.y
lex.yy.c: lex.l
	flex -o $@ lex.l
clean:
	rm parser.tab.c parser.tab.h lex.yy.c sql