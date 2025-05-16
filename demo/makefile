PROG_NAME = demo
PROG_OUT_DIR = bin
TEST_OUT_DIR = $(PROG_OUT_DIR)
PROG_BIN = $(PROG_OUT_DIR)/$(PROG_NAME)
TEST_BIN = $(TEST_OUT_DIR)/test_$(PROG_NAME)
PROG_SRC_DIR = src
TEST_SRC_DIR = test
INCLUDES_DIR = includes
PROG_FILES = $(shell find $(PROG_SRC_DIR) -type f -iname '*.c')
TEST_FILES = $(shell find $(TEST_SRC_DIR) -type f -iname '*.c') $(filter-out $(PROG_SRC_DIR)/main.c,$(PROG_FILES))
PROG_HFILES = $(shell find $(PROG_SRC_DIR) -type f -name '*.h')
TEST_HFILES = $(shell find $(TEST_SRC_DIR) -type f -name '*.h') $(PROG_HFILES)
LIBS = yaml-0.1 sqlite3
CFLAGS = -Wall -Wextra -pedantic -std=c18 $(shell pkg-config --cflags $(LIBS))
LDFLAGS = $(shell pkg-config --libs $(LIBS))


$(PROG_BIN): $(PROG_FILES) $(PROG_HFILES) makefile
	mkdir -p bin/
	$(CC) -o $(PROG_BIN) $(PROG_FILES) -I$(INCLUDES_DIR) $(CFLAGS) $(LDFLAGS)


$(TEST_BIN): $(TEST_FILES) $(TEST_HFILES) makefile
	@echo "doing test_bin"
	@echo "$(TEST_FILES)"
	mkdir -p bin/
	$(CC) -o $(TEST_BIN) $(TEST_FILES) -I$(INCLUDES_DIR) $(CFLAGS) $(LDFLAGS)


PHONY: build
build: $(PROG_BIN)


PHONY: test
test: $(TEST_BIN)
	@./$(TEST_BIN)


PHONY: run
run: $(PROG_BIN)
	@clear
	@./$(PROG_BIN)


PHONY: clean
clean:
	rm -rf result
	rm -rf $(PROG_OUT_DIR)
