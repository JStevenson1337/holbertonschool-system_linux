#ifndef __SIGNALS_H__
#define __SIGNALS_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <signal.h>



int handle_signal(void);
void signal_handler(int my_sig);
void (*current_handler_signal(void))(int);

#endif /* __SIGNALS_H__ */
