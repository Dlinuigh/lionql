DEPEND = parser.tab.c lex.yy.c
TARGET = lionql
PARSER_TARGET = sql
CC = gcc
FLEX = flex
BISON = bison
MESON = meson
BUILD_DIR = _build
MESON_SETUP_CMD = $(MESON) setup $(BUILD_DIR)
MESON_COMPILE_CMD = $(MESON) compile -C $(BUILD_DIR)

all: $(TARGET) $(PARSER_TARGET) $(BUILD_DIR)
	@$(MESON_COMPILE_CMD)
$(BUILD_DIR):
	@$(MESON_SETUP_CMD)
$(PARSER_TARGET): $(DEPEND)
	@$(CC) -o $@ $^ -lfl
debug: $(DEPEND)
	@$(CC) -DYYDEBUG=1 -o $(PARSER_TARGET) $^ -lfl
%.yy.c: %.l
	@$(FLEX) -o $@ $<
%.tab.c: %.y
	@$(BISON) -Wcounterexamples -o $@ -d $<
clean:
	@rm -f $(PARSER_TARGET) *.yy.c *.tab.c *.tab.h -r $(BUILD_DIR) $(TARGET)
