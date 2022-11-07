
0x00. C - Signals
 By: Alexandre Gautier, Software Engineer at Holberton School
 Weight: 1
 Project will start Nov 7, 2022 12:00 AM, must end by Nov 11, 2022 12:00 AM
 will be released at Nov 9, 2022 12:00 AM
 Manual QA review must be done (request it when you are done with the project)
 An auto review will be launched at the deadline
Resources
Read or watch:

Signals
Asynchrony
Signal sets
man or help:

signal (7)
signal (2)
sigaction (2)
kill (2)
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
What is a signal
Why do they exist
When are they delivered and by whom
What are the default actions of signals
How to set up a handler for a signal
How to send signals
What signals can’t be caught
Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are allowed to have more than 5 functions per file
The prototypes of all your functions should be included in your header file called signals.h
Don’t forget to push your header file
All your header files should be include guarded
Allowed functions and system calls
Unless specified otherwise in a task, you are allowed to use the C standard library
Quiz questions
Great! You've completed the quiz successfully! Keep going! (Show quiz)
Tasks
0. Handle signal
mandatory
Write a function that set a handler for the signal SIGINT

Prototype: int handle_signal(void);
Your function must return 0 on success, or -1 on error
The program should print Gotcha! [<signum>] followed by a new line, every time Control-C is pressed (See example below)
where <signum> must be replaced with the signal number that was caught
sigaction(2) is not allowed
alex@~/0x00-signals$ cat 0-main.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "signals.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int i;

    if (handle_signal() == -1)
    {
        printf("Failure\n");
        return (EXIT_FAILURE);
    }
    for (i = 0; ; i++)
    {
        printf("[%d] Wait for it ...\n", i);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-handle_signal.c -o 0-handle_signal
alex@~/0x00-signals$ ./0-handle_signal 
[0] Wait for it ...
[1] Wait for it ...
[2] Wait for it ...
^CGotcha! [2]
[3] Wait for it ...
^CGotcha! [2]
[4] Wait for it ...
[5] Wait for it ...
^CGotcha! [2]
[6] Wait for it ...
[7] Wait for it ...
^CGotcha! [2]
[8] Wait for it ...
[9] Wait for it ...
^\Quit (core dumped)
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 0-handle_signal.c
 
1. Current handler - signal
mandatory
Write a function that retrieves the current handler of the signal SIGINT

Prototype: void (*current_handler_signal(void))(int);
Your function returns a pointer to the current handler of SIGINT, or NULL on failure
You are not allowed to use sigaction(2)
The handler must be unchanged after calling your function
alex@~/0x00-signals$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "signals.h"

/* Our functions */
void print_hello(int);
void set_print_hello(void);

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    void (*handler)(int);
    int i;

    handler = current_handler_signal();
    printf("Address of the current handler: %#lx\n", (unsigned long int)handler);

    /* Set 'print_hello()` as the handler for SIGINT */
    set_print_hello();

    handler = current_handler_signal();
    printf("Address of the 'print_hello' function: %#lx\n", (unsigned long int)&print_hello);
    printf("Address of the current handler: %#lx\n", (unsigned long int)handler);

    for (i = 0; ; i++)
    {
        printf("[%d] Wait for it ...\n", i);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-set_print_hello.c 1-current_handler_signal.c -o 1-current_handler_signal
alex@~/0x00-signals$ ./1-current_handler_signal
Address of the current handler: 0
Address of the 'print_hello' function: 0x4006da
Address of the current handler: 0x4006da
[0] Wait for it ...
[1] Wait for it ...
^CHello :)
[2] Wait for it ...
^CHello :)
[3] Wait for it ...
[4] Wait for it ...
^CHello :)
[5] Wait for it ...
^\Quit (core dumped)
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 1-current_handler_signal.c
 
2. Gotta catch them all
mandatory
Write a function that set a handler for the signal SIGINT

Prototype: int handle_sigaction(void);
Your function must return 0 on success, or -1 on error
The program should print Gotcha! [<signum>] followed by a new line, every time Control-C is pressed (See example below)
where <signum> must be replaced with the signal number that was caught
signal(2) is not allowed
alex@~/0x00-signals$ cat 2-main.c 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "signals.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int i;

    if (handle_sigaction() == -1)
    {
        printf("Failure\n");
        return (EXIT_FAILURE);
    }
    for (i = 0; ; i++)
    {
        printf("[%d] Wait for it ...\n", i);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 2-main.c 2-handle_sigaction.c -o 2-handle_sigaction
alex@~/0x00-signals$ ./2-handle_sigaction 
[0] Wait for it ...
[1] Wait for it ...
^CGotcha! [2]
[2] Wait for it ...
[3] Wait for it ...
^CGotcha! [2]
[4] Wait for it ...
^CGotcha! [2]
[5] Wait for it ...
^CGotcha! [2]
[6] Wait for it ...
[7] Wait for it ...
^CGotcha! [2]
[8] Wait for it ...
^\Quit (core dumped)
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 2-handle_sigaction.c
 
3. Current handler - sigaction
mandatory
Write a function that retrieves the current handler of the signal SIGINT

Prototype: void (*current_handler_sigaction(void))(int);
Your function returns a pointer to the current handler of SIGINT, or NULL on failure
You have to use the function sigaction (signal is not allowed)
The handler must be unchanged after calling your function
alex@~/0x00-signals$ cat 3-main.c 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "signals.h"

/* Our functions */
void print_hello(int);
void set_print_hello(void);

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    void (*handler)(int);
    int i;

    handler = current_handler_sigaction();
    printf("Address of the current handler: %#lx\n", (unsigned long int)handler);

    /* Set 'print_hello()` as the handler for SIGINT */
    set_print_hello();

    handler = current_handler_sigaction();
    printf("Address of the 'print_hello' function: %#lx\n", (unsigned long int)&print_hello);
    printf("Address of the current handler: %#lx\n", (unsigned long int)handler);

    for (i = 0; ; i++)
    {
        printf("[%d] Wait for it ...\n", i);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 3-main.c 3-set_print_hello.c 3-current_handler_sigaction.c -o 3-current_handler_sigaction
alex@~/0x00-signals$ ./3-current_handler_sigaction 
Address of the current handler: 0
Address of the 'print_hello' function: 0x4006ea
Address of the current handler: 0x4006ea
[0] Wait for it ...
[1] Wait for it ...
^CHello :)
[2] Wait for it ...
^CHello :)
[3] Wait for it ...
[4] Wait for it ...
^CHello :)
[5] Wait for it ...
^CHello :)
[6] Wait for it ...
^\Quit (core dumped)
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 3-current_handler_sigaction.c
 
4. Who said that?!
mandatory
Write a function that defines a handler for the signal SIGQUIT (Control-\ in a shell)

Prototype: int trace_signal_sender(void);
The handler must print SIGQUIT sent by <pid> each time a SIGQUIT (and only a SIGQUIT) is caught
Where <pid> must be replaced by the PID of the process that sent the signal
Your function must return 0 on success, or -1 on error
alex@~/0x00-signals$ cat 4-main.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "signals.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int i;

    if (trace_signal_sender() == -1)
    {
        printf("Failure\n");
        return (EXIT_FAILURE);
    }
    for (i = 0; ; i++)
    {
        printf("[%d] Wait for it ...\n", i);
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 4-main.c 4-trace_signal_sender.c -o 4-trace_signal_sender
alex@~/0x00-signals$ ./4-trace_signal_sender
[0] Wait for it ...
[1] Wait for it ...
^\SIGQUIT sent by 0
[2] Wait for it ...
^\SIGQUIT sent by 0
[3] Wait for it ...
^\SIGQUIT sent by 0
[4] Wait for it ...
[5] Wait for it ...
^\SIGQUIT sent by 0
[6] Wait for it ...
[7] Wait for it ...
[8] Wait for it ...
SIGQUIT sent by 95337
[9] Wait for it ...
^C
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 4-trace_signal_sender.c
 
5. Description
mandatory
Write a program that prints a description of a given signal

Usage: ./describe <signum>
Where <signum> is the signal number to be described
If the number of arguments is not correct, your program must print Usage: %s <signum> (where %s is argv[0]), followed by a new line, and exit with EXIT_FAILURE
You’re not allowed to have more than 1 function in your file
You’re not allowed to have more than 12 lines in your function
You can assume that if a parameter is given, it will be a number
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 5-signal_describe.c -o 5-signal_describe
alex@~/0x00-signals$ ./5-signal_describe
Usage: ./5-signal_describe <signum>
alex@~/0x00-signals$ ./5-signal_describe 1
1: Hangup
alex@~/0x00-signals$ ./5-signal_describe 9
9: Killed
alex@~/0x00-signals$ ./5-signal_describe 3
3: Quit
alex@~/0x00-signals$ ./5-signal_describe 2
2: Interrupt
alex@~/0x00-signals$ ./5-signal_describe 0
0: Unknown signal 0
alex@~/0x00-signals$ ./5-signal_describe 100
100: Unknown signal 100
alex@~/0x00-signals$ ./5-signal_describe 20
20: Stopped
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 5-signal_describe.c
 
6. Catch a single time
mandatory
Write a program that sets a handler for the signal SIGINT, and exits right after the signal is received and handled

Your program does not take any argument
Your program should suspend indefinitely until a signal is received
When a SIGINT is received, you must print Caught %d (where %d must be replaced by the signal number), followed by a new line
After the first SIGINT is received, your program must:
Print Signal received, followed by a new line
Exit with EXIT_SUCCESS
You are not allowed to use the functions exit, sleep or _exit
You are not allowed to use any kind of loop (while, for, do/while)
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 6-suspend.c -o 6-suspend
alex@~/0x00-signals$ ./6-suspend 
^CCaught 2
Signal received
alex@~/0x00-signals$ echo $?
0
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 6-suspend.c
 
7. Sending a signal
mandatory
Write a program that sends the signal SIGINT to a process, given its PID

Usage: signal_send <pid>
Where <pid> is the PID of the process to send a signal to
If the number of arguments is not correct, your program must print Usage: %s <pid> (where %s is argv[0]), followed by a new line, and exit with EXIT_FAILURE
<pid> won’t be 0
Your program must return EXIT_SUCCESS on success, or EXIT_FAILURE
You’re not allowed to have more than 1 function in your file
alex@~/0x00-signals$ cat 7-main.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - Simple program, printing its PID and running infinitely
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("PID: %d\n", (int)pid);
    while (98)
    {
        printf("Waiting ...\n");
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 7-main.c -o 7-wait_for_it
alex@~/0x00-signals$ ./7-wait_for_it 
PID: 98631
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...

alex@~/0x00-signals$
While the above example is in its Waiting state, execute the following, and it should terminate the process above.

alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 7-signal_send.c -o 7-signal_send
alex@~/0x00-signals$ ./7-signal_send
Usage: ./7-signal_send <pid>
alex@~/0x00-signals$ ./7-signal_send 98631
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 7-signal_send.c
 
8. Sending a signal in a shell
mandatory
Write a sh script that sends the signal SIGQUIT to a process, given its PID

Usage: signal_send.sh <pid>
Where <pid> is the PID of the process to send a signal to
If the number of arguments is not correct, your program must print Usage: %s <pid> (where %s is argv[0]), followed by a new line, and exit with 1
alex@~/0x00-signals$ cat 8-main.c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - Simple program, printing its PID and running infinitely
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("PID: %d\n", (int)pid);
    while (98)
    {
        printf("Waiting ...\n");
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 8-main.c -o 8-wait_for_it
alex@~/0x00-signals$ ./8-wait_for_it 
PID: 98988
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...
Waiting ...

alex@~/0x00-signals$
While the above example is in its Waiting state, execute the following, and it should terminate the process above.

alex@~/0x00-signals$ sh ./8-signal_send.sh
Usage: ./8-signal_send <pid>
alex@~/0x00-signals$ sh ./8-signal_send.sh 98988
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 8-signal_send.sh
 
9. Catch with sh
mandatory
Write a sh script that set a handler for the signals SIGABRT, SIGIO and SIGTERM

The script must print Nope followed by a new line, each time a SIGABRT, SIGIO or SIGTERM is caught
Your script must contain a shebang
You’re not allowed to have more than 2 lines in your script
You’re not allowed to have more than 1 instruction per line
alex@~/0x00-signals$ cat 9-main.sh
#!/bin/sh
. ./9-handle_signal.sh

echo "PID: $$"

while :
do
    echo "Waiting ..."
    sleep 2
done
alex@~/0x00-signals$ sh 9-main.sh
PID: 99440
Waiting ...
Waiting ...
Nope
Waiting ...
Nope
Waiting ...
Nope
Waiting ...
Nope
Waiting ...
Waiting ...
Nope
Waiting ...
Nope
Waiting ...
Waiting ...
Waiting ...
Nope
Waiting ...
Nope
Waiting ...
Waiting ...
Killed
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 9-handle_signal.sh
 
10. Does it exist?
mandatory
Write a function that tests if a process exists, given its PID

Prototype: int pid_exist(pid_t pid);
Your function must return 1 if the process with the PID pid exists, or 0 otherwise
You’re not allowed to have more than 1 function in your file
You’re not allowed to have more than 1 line in your function
You’re not allowed to include more than 2 headers in your file
You’re not allowed to include your header file signals.h
You’re not allowed to use the function getpgid
alex@~/0x00-signals$ cat 10-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "signals.h"

/**
 * main - Entry point
 * @argc: Arguments counter
 * @argv: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, const char *argv[])
{
    pid_t pid;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return (EXIT_FAILURE);
    }
    pid = atoi(argv[1]);

    if (pid_exist(pid))
    {
        printf("PID %d exists\n", pid);
    }
    else
    {
        printf("PID %d does not exist\n", pid);
    }
    return (EXIT_SUCCESS);
}
alex@~/0x00-signals$ gcc -Wall -Wextra -Werror -pedantic 10-main.c 10-pid_exist.c -o 10-pid_exist
alex@~/0x00-signals$ ./10-pid_exist 1
PID 1 exists
alex@~/0x00-signals$ ./10-pid_exist 2
PID 2 exists
alex@~/0x00-signals$ ./10-pid_exist 1234
PID 1234 does not exist
alex@~/0x00-signals$ ./10-pid_exist 98
PID 98 does not exist
alex@~/0x00-signals$ ./10-pid_exist 890
PID 890 exists
alex@~/0x00-signals$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x00-signals
File: 10-pid_exist.c
 
11. Blog post
mandatory
Write a blog post about signals

Your blog post should cover the following:

What is a signal
Why do they exist
When are they delivered and by whom
What are the default actions of signals
What happens to a process when it receives a signal without handling it
What happens to a process when it receives a signal and handles it
Your posts should have examples and at least one picture, at the top. Publish your blog post on Medium or LinkedIn, and share it at least on LinkedIn.

When done, please add all urls below (blog post, tweet, etc.)

Please, remember that these blogs must be written in English to further your technical ability in a variety of settings.

Add URLs here:
Repo:

GitHub repository: holbertonschool-system_linux
 
Copyright © 2022 Holberton Inc, All rights reserved.
