# Makefile

NAME0 = todo_api_0
NAME1 = todo_api_1
NAME2 = todo_api_2
NAME3 = todo_api_3
NAME4 = todo_api_4
NAME5 = todo_api_5
NAME6 = todo_api_6
NAME7 = todo_api_7

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g
SRCDIR = src

TASK0 = todo_api_0
TASK1 = todo_api_1
TASK2 = todo_api_2
TASK3 = todo_api_3
TASK4 = todo_api_4
TASK5 = todo_api_5
TASK6 = todo_api_6
TASK7 = todo_api_7

INCLUDE = include

OBJ0 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK0)/*.c))
OBJ0 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ1 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK1)/*.c))
OBJ1 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ2 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK2)/*.c))
OBJ2 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ3 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK3)/*.c))
OBJ3 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ4 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK4)/*.c))
OBJ4 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ5 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK5)/*.c))
OBJ5 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ6 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK6)/*.c))
OBJ6 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))
OBJ7 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(TASK7)/*.c))
OBJ7 += $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/$(INCLUDE)/*.c))

$(NAME0): $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

$(NAME3): $(OBJ3)
	$(CC) $(OBJ3) -o $(NAME3)

$(NAME4): $(OBJ4)
	$(CC) $(OBJ4) -o $(NAME4)

$(NAME5): $(OBJ5)
	$(CC) $(OBJ5) -o $(NAME5)

$(NAME6): $(OBJ6)
	$(CC) $(OBJ6) -o $(NAME6)

$(NAME7): $(OBJ7)
	$(CC) $(OBJ7) -o $(NAME7)