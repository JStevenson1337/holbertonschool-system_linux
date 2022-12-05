# -*- MakeFile -*-

NAME0 = hnm
NAME1 = hobjdump 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g
SRCDIR = src
COMMON_DIR = hreadelf

TASK0 = symbolnames
TASK1 = objdump
COMMON = common_tools
COMMON_HEADER = print_header
OBJ0 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK0)/*.c))
OBJ1 += $(patsubst %.c, %.o, $(SRCDIR)/$(TASK1)/0-main.c)

$(NAME0): $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)
