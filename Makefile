# 定义目标和依赖文件
DEPEND = parser.tab.c lex.yy.c
TARGET = sql
CC = gcc
FLEX = flex
BISON = bison
# 默认目标
all: ${TARGET}

# 生成目标文件
${TARGET}: ${DEPEND}
	${CC} -o $@ $^ -lfl

# debug目标
debug: ${DEPEND}
	${CC} -DYYDEBUG=1 -o ${TARGET} $^ -lfl

# 使用 Flex 编译 .l 文件
%.yy.c: %.l
	${FLEX} -o $@ $<

# 使用 Bison 编译 .y 文件
%.tab.c: %.y
	${BISON} -Wcounterexamples -o $@ -d $<

# 清理中间文件
clean:
	rm -f ${TARGET} *.yy.c *.tab.c *.tab.h
