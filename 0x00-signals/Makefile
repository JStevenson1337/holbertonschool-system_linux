CC = gcc
DEBUGFLAGS = -g -DDEBUG

CFLAGS = -Wall -Werror -Wextra -pedantic
DEBUGFLAGS = $(CFLAGS) -g -DDEBUG
HEADERS = signals.h
Task0_Files = 0-main.c 0-handle_signal.c
Task1_files = 1-main.c 1-set_print_hello.c 1-current_handler_signal.c
Task2_files = 2-main.c 2-handle_sigaction.c
Task3_files = 3-main.c 3-set_print_hello.c 3-current_handler_sigaction.c
Task4_files = 4-main.c 4-trace_signal_sender.c
Task5_files = 5-signal_describe.c
Task6_files = 6-suspend.c
Task7_files = 7-main.c
Task8_files = 8-main.c
Task10_files = 10-main.c 10-pid_exist.c


Task_0: 
	$(CC) $(CFLAGS) $(Task0_Files) -o 0-handle_signal
Task_0_debug: 
	$(CC) $(DEBUGFLAGS) $(Task0_Files) -o 0-handle_signal_debug

Task_1:
	$(CC) $(CFLAGS) $(Task1_files) -o 1-current_handler_signal
Task_1_debug:
	$(CC) $(DEBUGFLAGS) $(Task1_files) -o 1-current_handler_signal_debug

Task_2:
	$(CC) $(CFLAGS) $(Task2_files) -o 2-handle_sigaction
Task_2_debug:
	$(CC) $(DEBUGFLAGS) $(Task2_files) -o 2-handle_sigaction_debug

Task_3:
	$(CC) $(CFLAGS) $(Task3_files) -o 3-current_handler_sigaction
Task_3_debug:
	$(CC) $(DEBUGFLAGS) $(Task3_files) -o 3-current_handler_sigaction_debug

Task_4:
	$(CC) $(CFLAGS) $(Task4_files) -o 4-trace_signal_sender
Task_4_debug:	
	$(CC) $(DEBUGFLAGS) $(Task4_files) -o 4-trace_signal_sender_debug

Task_5:
	$(CC) $(CFLAGS) $(Task5_files) -o 5-signal_describe
Task_5_debug:
	$(CC) $(DEBUGFLAGS) $(Task5_files) -o 5-signal_describe_debug

Task_6:
	$(CC) $(CFLAGS) $(Task6_files) -o 6-suspend
Task_6_debug:
	$(CC) $(DEBUGFLAGS) $(Task6_files) -o 6-suspend_debug

Task_7:
	$(CC) $(CFLAGS) $(Task7_files) -o 7-wait_for_it
Task_7_debug:
	$(CC) $(DEBUGFLAGS) $(Task7_files) -o 7-wait_for_it_debug

Task_8:
	$(CC) $(CFLAGS) $(Task8_files) -o 8-wait_for_it
Task_8_debug:
	$(CC) $(DEBUGFLAGS) $(Task8_files) -o 8-wait_for_it_debug

Task_10:
	$(CC) $(CFLAGS) $(Task10_files) -o 10-pid_exist
Task_10_debug:
	$(CC) $(DEBUGFLAGS) $(Task10_files) -o 10-pid_exist_debug



OBJ = 0-handle_signal.o 1-current_handler_signal.o 2-handle_sigaction.o 3-current_handler_sigaction.o 4-trace_signal_sender.o 5-signal_describe.o 6-suspend.o 7-wait_for_it.o 7-signal_send.o 8-wait_for_it.o 10-pid_exist.o

all: Task_0 Task_1 Task_2 Task_3 Task_4 Task_5 Task_6 Task_7 Task_8 Task_10


	@echo "********Done.*********"

debug: Task_0_debug Task_1_debug Task_2_debug Task_3_debug Task_4_debug Task_5_debug Task_6_debug Task_7_debug Task_8_debug Task_10_debug


	@echo "********Done.*********"


betty:
	@echo "Checking betty style..."
	@$(BETTYCHECK) *.c
	@echo "Done."

.PHONY: all clean betty


clean:
	rm -f 0-handle_signal 0-handle_signal_debug 1-current_handler_signal 1-current_handler_signal_debug 2-handle_sigaction 2-handle_sigaction_debug 3-current_handler_sigaction 3-current_handler_sigaction_debug 4-trace_signal_sender 4-trace_signal_sender_debug 5-signal_describe 5-signal_describe_debug 6-suspend 6-suspend_debug 7-wait_for_it 7-wait_for_it_debug 8-wait_for_it 8-wait_for_it_debug 10-pid_exist 10-pid_exist_debug
