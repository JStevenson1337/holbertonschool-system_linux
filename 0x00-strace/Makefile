#**~~ MAKEFILE ~~**#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CFDBUG = -g -DDEBUG
SRC = src/
STRACE_A = 0-main.c
STRACE_B = 1-main.c
STRACE_C = 2-main.c
STRACE_D = 3-main.c
RM = rm -rf

ALL:
	$(strace_0) $(strace_1) $(strace_2) $(strace_3)
strace_0: $(SRC)$(STRACE_A)
	$(CC) $(CFLAGS) $^ -o $@
strace_1: $(STRACE_B)
	$(CC) $(CFLAGS) $^ -o $@
strace_2: $(STRACE_C)
	$(CC) $(CFLAGS) $^ -o $@
strace_3: $(STRACE_D)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *~ $(STRACE_A) $(STRACE_B) $(STRACE_C) $(STRACE_D)
.PHONY: clean strace_0 strace_1 strace_2 strace_3
