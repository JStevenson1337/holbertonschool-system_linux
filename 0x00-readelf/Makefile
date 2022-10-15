ELF_HEARDER = "/usr/include/elf.h"
#
#
PATH_TO_BASE = ../..
SRC_DIR = $(PATH_TO_BASE)/src
BIN_DIR = $(SRC_DIR)/bin
TEST_DIR = $(SRC_DIR)/test

if [ ! -d $(SRC_DIR) ]; then mkdir $(SRC_DIR); fi
if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi
if [ ! -d $(TEST_DIR) ]; then mkdir $(TEST_DIR); fi

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJS = 

all: $(BIN_DIR)/test

$(BIN_DIR)/test: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test $(OBJS)

clean: test
	rm -f $(BIN_DIR)/test

test: $(BIN_DIR)/test
	$(BIN_DIR)/test

0-hreadelf: $(ELF_HEARDER)
	$(CC) $(CFLAGS) -c 0-hreadelf.c

1-hreadelf: $(ELF_HEARDER)
	$(CC) $(CFLAGS) -c 1-hreadelf.c

2-hreadelf: $(ELF_HEARDER)
	$(CC) $(CFLAGS) -c 2-hreadelf.c

100-hreadelf: $(ELF_HEARDER)
	$(CC) $(CFLAGS) -c 100-hreadelf.c

$(TARGETS): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJS): $(SRCS) $(HEADERS)
		$(CC) $(CFLAGS) -c $(SRCS)

clean: 
		rm -f $(OBJS) $(TARGETS)

.PHONY: all clean

# Path: main.c
# Run the program with the following command:
ifneq ($(wildcard $(BIN_DIR)/test),)
	$(BIN_DIR)/test
else
	@echo "Please compile the program first"
endif

# End of Makefile

