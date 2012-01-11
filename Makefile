CC=gcc

all: bin/line-buffer bin/ncurses-frontend

bin/line-buffer: src/line-buffer.c
	$(CC) -o bin/line-buffer src/line-buffer.c

bin/ncurses-frontend: src/ncurses-frontend.c
	$(CC) -o bin/ncurses-frontend src/ncurses-frontend.c -lncurses

check: test/check
	./test/check

clean:
	rm -f bin/line-buffer bin/ncurses-frontend
