CFLAGS = -std=c17 -pedantic -Wall -Wextra
UID = $(shell id -u)
GID = $(shell id -g)
PWD = $(shell pwd)

.PHONY: build
build: 
	gcc ${CFLAGS} -o hello-world hello-world.c

.PHONY: check
check:
	clang ${CFLAGS} --analyze hello-world.c
	cppcheck e=all hello-world.c

.PHONY: clean
clean:
	rm hello-world

.PHONY: run
run:
	@./hello-world


.PHONY: alpine-shell
alpine-shell:
	docker run -it --rm \
		--user ${UID}:${GID} \
		-v ${PWD}:/app \
		-v /etc/passwd:/etc/passwd \
		-v /etc/group:/etc/group \
		-w /app \
		alpine-dev \
		/bin/sh


.PHONY: shell-bookworm
bookworm-shell:
	docker run -it --rm \
		--user ${UID}:${GID} \
		-v ${PWD}:/app \
		-v /etc/passwd:/etc/passwd \
		-v /etc/group:/etc/group \
		-w /app \
		bookworm-dev \
		/bin/sh
