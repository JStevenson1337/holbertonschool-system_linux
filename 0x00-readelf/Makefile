CC        = gcc
CFLAGS    = -g3 -Wall -Werror -Wextra -pedantic
HEADER_FILE = hreadelf.h

0-hreadelf: 0-hreadelf.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -o $@ $<

1-hreadelf: 1-hreadelf.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -o $@ $<

2-hreadelf: 2-hreadelf.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f 0-hreadelf 1-hreadelf 2-hreadelf


