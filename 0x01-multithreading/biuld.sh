#!/usr/bin/env bash



# 0. Thread entry point
gcc -Wall -Wextra -Werror -pedantic -g3 0-main.c 0-thread_entry.c -o 0-thread_entry -pthread

#1. Thread Logger
gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c 1-tprintf.c -o 1-tprintf -pthread

#2. Blur portion of an image
gcc -Wall -Wextra -Werror -pedantic -g3 10-main.c 10-blur_portion.c -o 10-blur_portion

#3. Blur entire image
gcc -Wall -Wextra -Werror -pedantic -g3 11-main.c 11-blur_image.c 10-blur_portion.c -o 11-blur_image -pthread

#4. Thread logger v2
gcc -Wall -Wextra -Werror -pedantic -g3 20-main.c 20-tprintf.c -o 20-tprintf -pthread

#5. Number to prime factors
gcc -Wall -Wextra -Werror -pedantic -g3 21-main.c 21-prime_factors.c list.c -o 21-prime_factors


#6. Number to prime factors v2
gcc -Wall -Wextra -Werror -pedantic -g3 22-main.c 22-prime_factors.c 21-prime_factors.c list.c 20-tprintf.c -o 22-prime_factors -pthread
