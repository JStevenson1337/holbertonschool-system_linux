#**~~ MAKEFILE ~~**#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
# CFDBUG = -g3 -DDEBUG

SRC_DIR = src/
# OBJ_DIR = obj/
# INC_DIR = inc/

STRACE_A = 0-main.c
STRACE_B = 1-main.c
STRACE_C = 2-main.c
STRACE_D = 3-main.c
RM = rm -rf

# HEADERS = $(INC_DIR)*.h
# SOURCES = $(SRC_DIR)*.c
# OBJECTS = $(OBJ_DIR)*.o



# $(SRC_DIR)$(SOURCES) $(INC_DIR)$(HEADERS)

strace_0: $(SRC_DIR)$(STRACE_A)
	$(CC) $(CFLAGS) $^ -o $@
strace_1: $(SRC_DIR)$(STRACE_B)
	$(CC) $(CFLAGS) $^ -o $@
strace_2: $(SRC_DIR)$(STRACE_C)
	$(CC) $(CFLAGS) $^ -o $@
strace_3: $(SRC_DIR)$(STRACE_D)
	$(CC) $(CFLAGS) $^ -o $@

strace_0_debug: $(SRC_DIR)$(STRACE_A)
	$(CC) $(CFLAGS) $(CFDBUG) $^ -o $@
strace_1_debug: $(SRC_DIR)$(STRACE_B)
	$(CC) $(CFLAGS) $(CFDBUG) $^ -o $@
strace_2_debug: $(SRC_DIR)$(STRACE_C)
	$(CC) $(CFLAGS) $^ -o $@
strace_3_debug: $(SRC_DIR)$(STRACE_D)
	$(CC) $(CFLAGS) $(CFDBUG) $^ -o $@
clean:
	$(RM) *~ $(STRACE_A) $(STRACE_B) $(STRACE_C) $(STRACE_D)
.PHONY: clean strace_0 strace_1 strace_2 strace_3
