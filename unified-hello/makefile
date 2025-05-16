#
# Update the name and list of libs for the project.
#
NAME = demo
LIBS = yaml-0.1 sqlite3

#
# In most cases nothing below should need to change.
#

CFLAGS = -Wall -Wextra -pedantic -std=c18 $(shell pkg-config --cflags $(LIBS))
LDFLAGS = $(shell pkg-config --libs $(LIBS))

bin/$(NAME): $(wildcard src/*) makefile
	mkdir -p bin
	$(CC) -o bin/$(NAME) src/main.c $(CFLAGS) $(LDFLAGS)

bin/$(NAME)_test: $(wildcard src/*) makefile
	mkdir -p bin
	$(CC) -Dtest -o bin/$(NAME)_test src/main.c $(CFLAGS) $(LDFLAGS)

PHONY: test
test: bin/$(NAME)_test
	@./bin/$(NAME)_test

PHONY: run
run: bin/$(NAME)
	@clear
	@./bin/$(NAME)

PHONY: clean
clean:
	rm -rf result
	rm -rf bin
