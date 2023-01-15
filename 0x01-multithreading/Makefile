CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g3
LFLAGS = -pthread
DEPS = multithreading.h


# 0. Thread entry point
Task0: 0-main.c 0-thread_entry.c
	$(CC) $(CFLAGS) 0-main.c 0-thread_entry.c -o 0-thread_entry $(LFLAGS)

#1. Thread Logger
Task1:  1-main.c 1-tprintf.c
	$(CC) $(CFLAGS) 1-main.c 1-tprintf.c -o 1-tprintf $(LFLAGS)

#2. Blur portion of an image
Task2: 10-main.c 10-blur_portion.c
	$(CC) $(CFLAGS) 10-main.c 10-blur_portion.c -o 10-blur_portion

#3. Blur entire image
Task3: 11-main.c 11-blur_image.c 10-blur_portion.c
	$(CC) $(CFLAGS) 11-main.c 11-blur_image.c 10-blur_portion.c -o 11-blur_image $(LFLAGS)

#4. Thread logger v2
Task4: 20-main.c 20-tprintf.c
	$(CC) $(CFLAGS) 20-main.c 20-tprintf.c -o 20-tprintf $(LFLAGS)

#5. Number to prime factors
Task5: 21-main.c 21-prime_factors.c list.c
	$(CC) $(CFLAGS) 21-main.c 21-prime_factors.c list.c -o 21-prime_factors


#6. Number to prime factors v2
Task6: 22-main.c 22-prime_factors.c 21-prime_factors.c list.c 20-tprintf.c
	$(CC) $(CFLAGS) 22-main.c 22-prime_factors.c 21-prime_factors.c list.c 20-tprintf.c -o 22-prime_factors $(LFLAGS)
