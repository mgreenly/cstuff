#
# Set the program's name and the library dependencies.
#

NAME = demo
LIBS =

#
# In most cases there's no need to change anything else.
#

ifdef LIBS
CFLAGS = -Wall -Wextra -pedantic -std=c18 $(shell pkg-config --cflags $(LIBS))
LDFLAGS = $(shell pkg-config --libs $(LIBS))
else
CFLAGS = -Wall -Wextra -pedantic -std=c18
LDFLAGS =
endif

CHECKS = -fsanitize=address,undefined

bin/$(NAME): $(wildcard src/*) makefile
	mkdir -p bin
	$(CC) -o bin/$(NAME) src/main.c $(CFLAGS) $(LDFLAGS)

bin/$(NAME)_debug: $(wildcard src/*) makefile
	mkdir -p bin
	$(CC) -o bin/$(NAME)_debug src/main.c $(CFLAGS) -g3 -O0 $(LDFLAGS)

PHONY: all
all: bin/$(NAME) bin/$(NAME)_debug

PHONY: debug
debug: bin/$(NAME)_debug
	@gdb -q ./bin/$(NAME)_debug

PHONY: run
run: bin/$(NAME)
	@clear
	@./bin/$(NAME)

PHONY: install
install: all
	cp bin/$(NAME) ~/.local/bin/

PHONY: clean
clean:
	rm -rf result
	rm -rf bin
