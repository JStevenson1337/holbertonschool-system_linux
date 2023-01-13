#!/usr/bin/env bash

./strace_0 /bin/pwd
./strace_0 /bin/echo C is awesome
./strace_0 /usr/bin/which bash

./strace_1 /bin/pwd
./strace_1 /bin/echo C is awesome
./strace_1 /usr/bin/which bash

./strace_2 /bin/pwd
./strace_2 /bin/echo C is awesome
./strace_2 /usr/bin/which bash

./strace_3 /bin/pwd
./strace_3 /bin/echo C is awesome
./strace_3 /usr/bin/which bash
