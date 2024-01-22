CC = cc
CFLAGS = -Wall -Wextra -DDEBUG -g

c2b : c2b.c
	$(CC) -o c2b c2b.c

install: c2b
	cp c2b /usr/local/bin/c2b
	rm -f c2b

clean:
	rm -f c2b