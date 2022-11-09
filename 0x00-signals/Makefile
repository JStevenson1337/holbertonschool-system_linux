CC = -Wall -Wextra -Werror -pedantic
DEBUGFLAGS = -g -DDEBUG

CFLAGS = $(CC)
CDEBUGFLAGS = $(CC) $(DEBUGFLAGS)

BETTYCHECK = betty-style.pl betty-doc.pl

all:


Task_1: 
	gcc $(CFLAGS) -o 0-main.c 0-handle_signal.c -o 0-handle_signal

Task_2:
	gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-set_print_hello.c 1-current_handler_signal.c -o 1-current_handler_signal

Task_3:
	gcc -Wall -Wextra -Werror -pedantic 2-main.c 2-handle_sigaction.c -o 2-handle_sigaction

Task_4:
	gcc -Wall -Wextra -Werror -pedantic 3-main.c 3-set_print_hello.c 3-current_handler_sigaction.c -o 3-current_handler_sigaction


Task_5:
	gcc -Wall -Wextra -Werror -pedantic 4-main.c 4-trace_signal_sender.c -o 4-trace_signal_sender

Task_6:
	gcc -Wall -Wextra -Werror -pedantic 5-signal_describe.c -o 5-signal_describe

Task_7:
	gcc -Wall -Wextra -Werror -pedantic 6-suspend.c -o 6-suspend

Task_8:
	gcc -Wall -Wextra -Werror -pedantic 7-main.c -o 7-wait_for_it

Task_9:
	gcc -Wall -Wextra -Werror -pedantic 7-signal_send.c -o 7-signal_send

Task_10:
	gcc -Wall -Wextra -Werror -pedantic 8-main.c -o 8-wait_for_it

Task_11:
	gcc -Wall -Wextra -Werror -pedantic 10-main.c 10-pid_exist.c -o 10-pid_exist

clean:
	rm -f 0-handle_signal
	rm -f 1-current_handler_signal
	rm -f 2-handle_sigaction
	rm -f 3-current_handler_sigaction
	rm -f 4-trace_signal_sender
	rm -f 5-signal_describe
	rm -f 6-suspend
	rm -f 7-wait_for_it
	rm -f 7-signal_send
	rm -f 8-wait_for_it
	rm -f 10-pid_exist
