      Project: 0x00. C - Strace | Holberton Tulsa, OK, USA Intranet          Cookies.set('timezone', (new Date()).getTimezoneOffset() / -60.0);  

Toggle navigation[

](/)

*   [
    
    Help
    
    ](https://students-support.hbtn.io/hc)
*   [
    
    My Planning
    
    ](/planning/me)
*   [
    
    Projects
    
    ](/projects/current)
*   [
    
    My reports
    
    ](/users/my_reports)
*   [
    
    QA Reviews I can make
    
    ](/corrections/to_review)
*   [
    
    Mock interviews
    
    ](/dashboards/my_current_reefineries)

* * *

*   [
    
    Curriculums
    
    ](/dashboards/my_curriculums)
*   [
    
    Concepts
    
    ](/concepts)
*   [
    
    Conference rooms
    
    ](/dashboards/video_rooms)
*   [
    
    Servers
    
    ](/servers)
*   [
    
    Sandboxes
    
    ](/user_containers/current)
*   [
    
    Tools
    
    ](/dashboards/my_tools)
*   [
    
    Video on demand
    
    ](/dashboards/videos)

* * *

*   [
    
    Peers
    
    ](/users/peers)
*   [
    
    Captain's Logs
    
    ](/dashboards/my_captain_log)
*   [
    
    Officers
    
    ](/dashboards/my_officers)

* * *

*   [
    
    Slack
    
    ](https://holberton-school-org.slack.com)
    
    [
    
    My Profile
    
    ](/users/my_profile)
    

[

](/)

*   [
    
    Help
    
    ](https://students-support.hbtn.io/hc)
*   [
    
    My Planning
    
    ](/planning/me)
*   [
    
    Projects
    
    ](/projects/current)
*   [
    
    My reports
    
    ](/users/my_reports)
*   [
    
    QA Reviews I can make
    
    ](/corrections/to_review)
*   [
    
    Mock interviews
    
    ](/dashboards/my_current_reefineries)

* * *

*   [
    
    Curriculums
    
    ](/dashboards/my_curriculums)
*   [
    
    Concepts
    
    ](/concepts)
*   [
    
    Conference rooms
    
    ](/dashboards/video_rooms)
*   [
    
    Servers
    
    ](/servers)
*   [
    
    Sandboxes
    
    ](/user_containers/current)
*   [
    
    Tools
    
    ](/dashboards/my_tools)
*   [
    
    Video on demand
    
    ](/dashboards/videos)

* * *

*   [
    
    Peers
    
    ](/users/peers)
*   [
    
    Captain's Logs
    
    ](/dashboards/my_captain_log)
*   [
    
    Officers
    
    ](/dashboards/my_officers)

* * *

*   [
    
    Slack
    
    ](https://holberton-school-org.slack.com)
    
    [
    
    My Profile
    
    ](/users/my_profile)
    

You just released the optional tasks of this project. Have fun!

0x00. C - Strace
================

### Concepts

_For this project, we expect you to look at these concepts:_

*   [\[EYNTK\] x86-64 Assembly](/concepts/770)
*   [\[EYNTK\] Strace](/concepts/771)

Resources
---------

**Read or watch**:

*   [Ptrace Tutorial](/rltoken/U9v8U91bRVv5eHuj6uR_wQ "Ptrace Tutorial")
*   [How does ptrace work](/rltoken/RzhtS9NgR7qpqCoSDeJyag "How does ptrace work")

**man or help**:

*   `strace`
*   `ptrace`

Learning Objectives
-------------------

At the end of this project, you are expected to be able to [explain to anyone](/rltoken/zRe7CZN8J4V-ZDw-yPRjeA "explain to anyone"), **without the help of Google**:

### General

*   What is strace, and what is its purpose
*   What is ptrace, and what possibilties it offers
*   What are the differences between `PTRACE_SINGLESTEP` and `PTRACE_SYSCALL`
*   How to read from and/or write to the memory of a process being traced

Requirements
------------

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be compiled on Ubuntu 14.04 LTS
*   Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
*   All your files should end with a new line
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
*   You are not allowed to use global variables
*   No more than 5 functions per file
*   You are allowed to use the standard library
*   All your header files should be include guarded
*   In the examples given, please remember that some values may be specific to the computer they are tested on, especially for addresses

More Info
---------

### Data Structure

This project requires you to parse the files `/usr/include/asm/unistd_64.h` and `/usr/include/asm/unistd_32.h`, in order to get the number corresponding to each syscall. It also requires you to do some man-scraping to get information about syscalls prototypes, in order to know the return type of each syscall, as well as its number of arguments and their type.

Since this is a very time-consuming task, you are given a [header file](https://github.com/hs-hq/0x0B-strace.c "header file"), containing all these informations, allowing you to focus on the `ptrace` part of this project.

Please note that you are completely allowed to use your own data structure(s) and/or to modify the one provided to you, which is only here to help you getting started with `strace`, it does not contain everything you need for a complete `strace`.

### Quiz questions

**Great!** You've completed the quiz successfully! Keep going!

#### Question #0

What is `strace`?

*   `strace` is a tool one can use to trace all the function calls made by a running process
    
*   `strace` is a tool one can use to trace all the system calls made by a running process
    
*   `strace` is a tool one can use to disassemble an executable file (elf format only)
    

#### Question #1

What is a system call?

*   The programmatic way in which a computer program requests a service from the kernel of the operating system it is executed on
    
*   System calls are much faster than regular library functions
    
*   System calls provide an essential interface between a process and the operating system.
    
*   `execve` is a system call
    
*   `fork` is a system call
    
*   `read` is a system call
    
*   `malloc` is a system call
    
*   `printf` is a system call
    
*   System calls only exist on Linux and Unix
    
*   Since the system calls are part of the OS, the application programs need to context switch from user space to kernel space whenever a system call is invoked
    

#### Question #2

What system call can we use to trace a running process?

*   `strace`
    
*   `ptrace`
    
*   `ktrace`
    

#### Question #3

What is `ptrace`?

*   A system call
    
*   The `ptrace` system call provides a means by which one process (the “tracer”) may observe and control the execution of another process (the “tracee”)
    
*   The `ptrace` system call provides a means by which one process (the “tracer”) may examine and change the tracee’s memory and registers
    
*   `ptrace` is primarily used to implement breakpoint debugging and system call tracing
    
*   It is an abbreviation of “process trace”
    
*   `ptrace` can only be found in some of Unix and Unix-like operating systems
    

Tasks
-----

### 0\. Step #0 - Syscall number

mandatory

Write a program that executes and traces a given command.

*   Usage: `./strace_0 command [args...]`
*   Each time a syscall is intercepted, you must print its number, followed by a new line
*   You don’t have to handle the `PATH`: `command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
*   Your Makefile must implement a rule `strace_0`

    alex@~/0x00-strace$ make strace_0
    [...]
    alex@~/0x00-strace$ ./strace_0 /bin/echo Holberton
    59
    12
    21
    9
    21
    2
    5
    9
    3
    21
    2
    0
    5
    9
    10
    9
    9
    3
    9
    9
    158
    10
    10
    10
    11
    12
    12
    2
    5
    9
    3
    5
    9
    1
    Holberton
    3
    11
    3
    231
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "0. Step #0 - Syscall number"

Check your code

×

#### Correction of "0. Step #0 - Syscall number"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 1\. Step #1 - Syscall name

mandatory

Write a program that executes and traces a given command.

*   Usage: `./strace_1 command [args...]`
*   Each time a syscall is intercepted, you must print its name, followed by a new line
*   You don’t have to handle the `PATH`: `command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
*   Your Makefile must implement a rule `strace_1`

    alex@~/0x00-strace$ make strace_1
    [...]
    alex@~/0x00-strace$ ./strace_1 /bin/echo Holberton
    execve
    brk
    access
    mmap
    access
    open
    fstat
    mmap
    close
    access
    open
    read
    fstat
    mmap
    mprotect
    mmap
    mmap
    close
    mmap
    mmap
    arch_prctl
    mprotect
    mprotect
    mprotect
    munmap
    brk
    brk
    open
    fstat
    mmap
    close
    fstat
    mmap
    writeHolberton
    
    close
    munmap
    close
    exit_group
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "1. Step #1 - Syscall name"

Check your code

×

#### Correction of "1. Step #1 - Syscall name"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 2\. Step #2 - Return value

mandatory

Write a program that executes and traces a given command.

*   Usage: `./strace_2 command [args...]`
*   Each time a syscall is intercepted, you must print its name and its return value in hexadecimal, followed by a new line (see example)
*   You don’t have to handle the `PATH`: `command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
*   Your Makefile must implement a rule `strace_2`
*   NOTES: It is impossible to retrieve the last system call return value, simply because it doesn’t return. So, just print a `?` like `strace` does.

    alex@~/0x00-strace$ make strace_2
    [...]
    alex@~/0x00-strace$ ./strace_2 /bin/echo Holberton
    execve = 0
    brk = 0xa98000
    access = 0xfffffffffffffffe
    mmap = 0x7fead97b8000
    access = 0xfffffffffffffffe
    open = 0x3
    fstat = 0
    mmap = 0x7fead97ad000
    close = 0
    access = 0xfffffffffffffffe
    open = 0x3
    read = 0x340
    fstat = 0
    mmap = 0x7fead91cf000
    mprotect = 0
    mmap = 0x7fead958d000
    mmap = 0x7fead9593000
    close = 0
    mmap = 0x7fead97ac000
    mmap = 0x7fead97aa000
    arch_prctl = 0
    mprotect = 0
    mprotect = 0
    mprotect = 0
    munmap = 0
    brk = 0xa98000
    brk = 0xab9000
    open = 0x3
    fstat = 0
    mmap = 0x7fead9621000
    close = 0
    fstat = 0
    mmap = 0x7fead97b7000
    writeHolberton
     = 0xa
    close = 0
    munmap = 0
    close = 0
    exit_group = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "2. Step #2 - Return value"

Check your code

×

#### Correction of "2. Step #2 - Return value"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 3\. Step #3 - Raw parameters

mandatory

Write a program that executes and traces a given command.

*   Usage: `./strace_3 command [args...]`
*   Each time a syscall is intercepted, you must print its name, its parameters in hexadecimal, and its return value in hexadecimal, followed by a new line (see example)
*   There’s a difficulty: The number of parameters is not the same for all syscalls…
*   You DON’T have to handle varargs:
    *   In case of a variadic system call, just print `...`
    *   Example with the `ioctl` syscall: `ioctl(0x3, 0x1, ...) = 0` (These are random values…)
*   You don’t have to handle the `PATH`: `command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
*   Your Makefile must implement a rule `strace_3`
*   NOTE: Refer to the previous `x86-64_Assembly` project to know where to find the arguments

    alex@~/0x00-strace$ make strace_3
    [...]
    alex@~/0x00-strace$ ./strace_3 /bin/echo Holberton
    execve(0, 0, 0) = 0
    brk(0) = 0x9a2000
    access(0x7f9c5add9aa0, 0) = 0xfffffffffffffffe
    mmap(0, 0x2000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f9c5afdd000
    access(0x7f9c5addc5b0, 0x4) = 0xfffffffffffffffe
    open(0x7f9c5add9fd6, 0x80000) = 0x3
    fstat(0x3, 0x7ffdec09fc80) = 0
    mmap(0, 0xa484, 0x1, 0xffffffffffffffff, 0x3, 0) = 0x7f9c5afd2000
    close(0x3) = 0
    access(0x7f9c5add9aa0, 0) = 0xfffffffffffffffe
    open(0x7f9c5afdb377, 0x80000) = 0x3
    read(0x3, 0x7ffdec09fe20, 0x340) = 0x340
    fstat(0x3, 0x7ffdec09fcd0) = 0
    mmap(0, 0x3c82c0, 0x5, 0xffffffffffffffff, 0x3, 0) = 0x7f9c5a9f4000
    mprotect(0x7f9c5abb2000, 0x200000, 0) = 0
    mmap(0x7f9c5adb2000, 0x6000, 0x3, 0xffffffffffffffff, 0x3, 0x1be000) = 0x7f9c5adb2000
    mmap(0x7f9c5adb8000, 0x42c0, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f9c5adb8000
    close(0x3) = 0
    mmap(0, 0x1000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f9c5afd1000
    mmap(0, 0x2000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f9c5afcf000
    arch_prctl(0x1002, 0x7f9c5afcf740) = 0
    mprotect(0x7f9c5adb2000, 0x4000, 0x1) = 0
    mprotect(0x606000, 0x1000, 0x1) = 0
    mprotect(0x7f9c5afdf000, 0x1000, 0x1) = 0
    munmap(0x7f9c5afd2000, 0xa484) = 0
    brk(0) = 0x9a2000
    brk(0x9c3000) = 0x9c3000
    open(0x7f9c5ab7cae0, 0x80000) = 0x3
    fstat(0x3, 0x7f9c5adb7b60) = 0
    mmap(0, 0x1887f0, 0x1, 0xffffffffffffffff, 0x3, 0) = 0x7f9c5ae46000
    close(0x3) = 0
    fstat(0x1, 0x7ffdec0a03e0) = 0
    mmap(0, 0x1000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f9c5afdc000
    write(0x1, 0x7f9c5afdc000, 0xaHolberton
    ) = 0xa
    close(0x1) = 0
    munmap(0x7f9c5afdc000, 0x1000) = 0
    close(0x2) = 0
    exit_group(0) = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "3. Step #3 - Raw parameters"

Check your code

×

#### Correction of "3. Step #3 - Raw parameters"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 4\. Step #4 - Strings

#advanced

Write a program that executes and traces a given command.

*   Usage: `./strace_4 command [args...]`
*   Same as the previous task (`Step #3`), but you must display `char *` parameters (see example)
*   Your Makefile must implement a rule `strace_4`

**Quick tip**: For the first syscall (`execve`), you have to print the parameters yourself, you cannot retrieve them. Why? Remember how `execve` works? :) It “overrides” the process memory with the binary we give it the path to. So, to simplify, `ptrace` will detect that `execve` is called, but when it is, the memory of your child process has be overwritten, so it’s impossible to get the parameters…

    alex@~/0x00-strace$ make strace_4
    [...]
    alex@~/0x00-strace$ ./strace_4 /bin/echo Holberton
    execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 21 vars */]) = 0
    brk(0) = 0x12aa000
    access("/etc/ld.so.nohwcap", 0) = 0xfffffffffffffffe
    mmap(0, 0x2000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f6ff0cb0000
    access("/etc/ld.so.preload", 0x4) = 0xfffffffffffffffe
    open("/etc/ld.so.cache", 0x80000) = 0x3
    fstat(0x3, 0x7ffe7c3aeeb0) = 0
    mmap(0, 0xa484, 0x1, 0xffffffffffffffff, 0x3, 0) = 0x7f6ff0ca5000
    close(0x3) = 0
    access("/etc/ld.so.nohwcap", 0) = 0xfffffffffffffffe
    open("/lib/x86_64-linux-gnu/libc.so.6", 0x80000) = 0x3
    read(0x3, 0x7ffe7c3af050, 0x340) = 0x340
    fstat(0x3, 0x7ffe7c3aef00) = 0
    mmap(0, 0x3c82c0, 0x5, 0xffffffffffffffff, 0x3, 0) = 0x7f6ff06c7000
    mprotect(0x7f6ff0885000, 0x200000, 0) = 0
    mmap(0x7f6ff0a85000, 0x6000, 0x3, 0xffffffffffffffff, 0x3, 0x1be000) = 0x7f6ff0a85000
    mmap(0x7f6ff0a8b000, 0x42c0, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f6ff0a8b000
    close(0x3) = 0
    mmap(0, 0x1000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f6ff0ca4000
    mmap(0, 0x2000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f6ff0ca2000
    arch_prctl(0x1002, 0x7f6ff0ca2740) = 0
    mprotect(0x7f6ff0a85000, 0x4000, 0x1) = 0
    mprotect(0x606000, 0x1000, 0x1) = 0
    mprotect(0x7f6ff0cb2000, 0x1000, 0x1) = 0
    munmap(0x7f6ff0ca5000, 0xa484) = 0
    brk(0) = 0x12aa000
    brk(0x12cb000) = 0x12cb000
    open("/usr/lib/locale/locale-archive", 0x80000) = 0x3
    fstat(0x3, 0x7f6ff0a8ab60) = 0
    mmap(0, 0x1887f0, 0x1, 0xffffffffffffffff, 0x3, 0) = 0x7f6ff0b19000
    close(0x3) = 0
    fstat(0x1, 0x7ffe7c3af610) = 0
    mmap(0, 0x1000, 0x3, 0xffffffffffffffff, 0xffffffff, 0) = 0x7f6ff0caf000
    write(0x1, 0x7f6ff0caf000, 0xaHolberton
    ) = 0xa
    close(0x1) = 0
    munmap(0x7f6ff0caf000, 0x1000) = 0
    close(0x2) = 0
    exit_group(0) = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "4. Step #4 - Strings"

Check your code

×

#### Correction of "4. Step #4 - Strings"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 5\. Step #5 - Integers

#advanced

Write a program that executes and traces a given command.

*   Usage: `./strace_5 command [args...]`
*   Same as the previous task (`Step #4`), but you must display integer parameters and return values. You must handle the following types:
    *   `int`
    *   `long`
    *   `size_t`
    *   `ssize_t`
    *   `u64`
    *   `uint32_t`
    *   `unsigned int`
    *   `unsigned long`
    *   `pid_t`
*   Your Makefile must implement a rule `strace_5`
*   NOTE: On failure, most syscalls return `-1`. You might get other values when you retrieve return values. This is simply the negated `errno` code, so don’t worry about that now.

    alex@~/0x00-strace$ make strace_5
    [...]
    alex@~/0x00-strace$ ./strace_5 /bin/echo Holberton
    execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 21 vars */]) = 0
    brk(0) = 34295808
    access("/etc/ld.so.nohwcap", 0) = -2
    mmap(0, 8192, 3, -1, -1, 0) = 0x7f1c75ea0000
    access("/etc/ld.so.preload", 4) = -2
    open("/etc/ld.so.cache", 524288) = 3
    fstat(3, 0x7ffcf7b85db0) = 0
    mmap(0, 42116, 1, -1, 3, 0) = 0x7f1c75e95000
    close(3) = 0
    access("/etc/ld.so.nohwcap", 0) = -2
    open("/lib/x86_64-linux-gnu/libc.so.6", 524288) = 3
    read(3, 0x7ffcf7b85f50, 832) = 832
    fstat(3, 0x7ffcf7b85e00) = 0
    mmap(0, 3965632, 5, -1, 3, 0) = 0x7f1c758b7000
    mprotect(0x7f1c75a75000, 2097152, 0) = 0
    mmap(0x7f1c75c75000, 24576, 3, -1, 3, 0x1be000) = 0x7f1c75c75000
    mmap(0x7f1c75c7b000, 17088, 3, -1, -1, 0) = 0x7f1c75c7b000
    close(3) = 0
    mmap(0, 4096, 3, -1, -1, 0) = 0x7f1c75e94000
    mmap(0, 8192, 3, -1, -1, 0) = 0x7f1c75e92000
    arch_prctl(4098, 139760214026048) = 0
    mprotect(0x7f1c75c75000, 16384, 1) = 0
    mprotect(0x606000, 4096, 1) = 0
    mprotect(0x7f1c75ea2000, 4096, 1) = 0
    munmap(0x7f1c75e95000, 42116) = 0
    brk(0) = 34295808
    brk(0x20d6000) = 34430976
    open("/usr/lib/locale/locale-archive", 524288) = 3
    fstat(3, 0x7f1c75c7ab60) = 0
    mmap(0, 1607664, 1, -1, 3, 0) = 0x7f1c75d09000
    close(3) = 0
    fstat(1, 0x7ffcf7b86510) = 0
    mmap(0, 4096, 3, -1, -1, 0) = 0x7f1c75e9f000
    write(1, 0x7f1c75e9f000, 10Holberton
    ) = 10
    close(1) = 0
    munmap(0x7f1c75e9f000, 4096) = 0
    close(2) = 0
    exit_group(0) = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "5. Step #5 - Integers"

Check your code

×

#### Correction of "5. Step #5 - Integers"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 6\. Step #6 - Macros

#advanced

Write a program that executes and traces a given command.

*   Usage: `./strace_6 command [args...]`
*   Same as the previous task (`Step #5`), plus you must interpret the following macros and flags:
    *   `NULL`
    *   All the flags for the `mmap`, `open` and `access` functions
*   Your Makefile must implement a rule `strace_6`

    alex@~/0x00-strace$ make strace_6
    [...]
    alex@~/0x00-strace$ ./strace_6 /bin/echo Holberton
    execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 21 vars */]) = 0
    brk(0) = 34295808
    access("/etc/ld.so.nohwcap", F_OK) = -2
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8894000
    access("/etc/ld.so.preload", R_OK) = -2
    open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, 0x7ffcf7b85db0) = 0
    mmap(NULL, 42116, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd6f8889000
    close(3) = 0
    access("/etc/ld.so.nohwcap", F_OK) = -2
    open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, 0x7ffcf7b85f50, 832) = 832
    fstat(3, 0x7ffcf7b85e00) = 0
    mmap(NULL, 3965632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fd6f82ab000
    mprotect(0x7fd6f8469000, 2097152, 0) = 0
    mmap(0x7fd6f8669000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1be000) = 0x7fd6f8669000
    mmap(0x7fd6f866f000, 17088, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fd6f866f000
    close(3) = 0
    mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8888000
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8886000
    arch_prctl(4098, 0x7fd6f8886740) = 0
    mprotect(0x7fd6f8669000, 16384, 1) = 0
    mprotect(0x606000, 4096, 1) = 0
    mprotect(0x7fd6f8896000, 4096, 1) = 0
    munmap(0x7fd6f8889000, 42116) = 0
    brk(0) = 0x2526000
    brk(0x2547000) = 0x2547000
    open("/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, 0x7f1c75c7ab60) = 0
    mmap(NULL, 1607664, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd6f86fd000
    close(3) = 0
    fstat(1, 0x7ffcf7b86510) = 0
    mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8893000
    write(1, 0x7fd6f8893000, 10Holberton
    ) = 10
    close(1) = 0
    munmap(0x7fd6f8893000, 4096) = 0
    close(2) = 0
    exit_group(0) = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "6. Step #6 - Macros"

Check your code

×

#### Correction of "6. Step #6 - Macros"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 7\. Step #7 - Buffer

#advanced

Write a program that executes and traces a given command.

*   Usage: `./strace_7 command [args...]`
*   Same as the previous task (`Step #6`), plus you must interpret the buffers for the `read` and `write` functions (see example)
    *   If the buffer size is greater than `32`, you must print only the first `32` characters, followed by `...`
    *   Non printable characters should be written `\OCT` where `OCT` is the ascii code in octal, excepted for the following: `\a`, `\b`, `\t`, `\n`, `\v`, `\f` and `\r`.
*   Your Makefile must implement a rule `strace_7`

    alex@~/0x00-strace$ make strace_7
    [...]
    alex@~/0x00-strace$ ./strace_7 /bin/echo Holberton
    execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 21 vars */]) = 0
    brk(0) = 34295808
    access("/etc/ld.so.nohwcap", F_OK) = -2
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8894000
    access("/etc/ld.so.preload", R_OK) = -2
    open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, 0x7ffcf7b85db0) = 0
    mmap(NULL, 42116, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd6f8889000
    close(3) = 0
    access("/etc/ld.so.nohwcap", F_OK) = -2
    open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P \2\0\0\0\0\0"..., 832) = 832
    fstat(3, 0x7ffcf7b85e00) = 0
    mmap(NULL, 3965632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fd6f82ab000
    mprotect(0x7fd6f8469000, 2097152, 0) = 0
    mmap(0x7fd6f8669000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1be000) = 0x7fd6f8669000
    mmap(0x7fd6f866f000, 17088, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fd6f866f000
    close(3) = 0
    mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8888000
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8886000
    arch_prctl(4098, 0x7fd6f8886740) = 0
    mprotect(0x7fd6f8669000, 16384, 1) = 0
    mprotect(0x606000, 4096, 1) = 0
    mprotect(0x7fd6f8896000, 4096, 1) = 0
    munmap(0x7fd6f8889000, 42116) = 0
    brk(0) = 0x2526000
    brk(0x2547000) = 0x2547000
    open("/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, 0x7f1c75c7ab60) = 0
    mmap(NULL, 1607664, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd6f86fd000
    close(3) = 0
    fstat(1, 0x7ffcf7b86510) = 0
    mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8893000
    write(1, "Holberton\n", 10Holberton
    ) = 10
    close(1) = 0
    munmap(0x7fd6f8893000, 4096) = 0
    close(2) = 0
    exit_group(0) = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "7. Step #7 - Buffer"

Check your code

×

#### Correction of "7. Step #7 - Buffer"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

### 8\. Step #8 - Structure

#advanced

Write a program that executes and traces a given command.

*   Usage: `./strace_8 command [args...]`
*   Same as the previous task (`Step #7`), plus you must interpret the structures for the `fstat` function
    *   You must only print `st_mode` and `st_size`, followed by `...` (See example)
*   Your Makefile must implement a rule `strace_8`

    alex@~/0x00-strace$ make strace_8
    [...]
    alex@~/0x00-strace$ ./strace_8 /bin/echo Holberton
    execve("/bin/echo", ["/bin/echo", "Holberton"], [/* 21 vars */]) = 0
    brk(0) = 34295808
    access("/etc/ld.so.nohwcap", F_OK) = -2
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8894000
    access("/etc/ld.so.preload", R_OK) = -2
    open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, {st_mode=S_IFREG|0644, st_size=39640, ...}) = 0
    mmap(NULL, 42116, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd6f8889000
    close(3) = 0
    access("/etc/ld.so.nohwcap", F_OK) = -2
    open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P \2\0\0\0\0\0"..., 832) = 832
    fstat(3, {st_mode=S_IFREG|0755, st_size=1857312, ...}) = 0
    mmap(NULL, 3965632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fd6f82ab000
    mprotect(0x7fd6f8469000, 2097152, 0) = 0
    mmap(0x7fd6f8669000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1be000) = 0x7fd6f8669000
    mmap(0x7fd6f866f000, 17088, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fd6f866f000
    close(3) = 0
    mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8888000
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8886000
    arch_prctl(4098, 0x7fd6f8886740) = 0
    mprotect(0x7fd6f8669000, 16384, 1) = 0
    mprotect(0x606000, 4096, 1) = 0
    mprotect(0x7fd6f8896000, 4096, 1) = 0
    munmap(0x7fd6f8889000, 42116) = 0
    brk(0) = 0x2526000
    brk(0x2547000) = 0x2547000
    open("/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, {st_mode=S_IFREG|0644, st_size=1607664, ...}) = 0
    mmap(NULL, 1607664, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fd6f86fd000
    close(3) = 0
    fstat(1, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
    mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fd6f8893000
    write(1, "Holberton\n", 10Holberton
    ) = 10
    close(1) = 0
    munmap(0x7fd6f8893000, 4096) = 0
    close(2) = 0
    exit_group(0) = ?
    alex@~/0x00-strace$
    

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x00-strace`
*   File: `Makefile`

Done?! Help

×

#### Students who are done with "8. Step #8 - Structure"

Check your code

×

#### Correction of "8. Step #8 - Structure"

Start a new test Close

Requirement success

Requirement fail

Code success

Code fail

Efficiency success

Efficiency fail

Text answer success

Text answer fail

Skipped - Previous check failed

Copyright © 2023 Holberton Inc, All rights reserved.

×

#### Markdown Guide

#### Emphasis

\*\***bold**\*\*
\*_italics_\*
~~strikethrough~~

#### Headers

\# Big header
## Medium header
### Small header
#### Tiny header

#### Lists

\* Generic list item
\* Generic list item
\* Generic list item

1. Numbered list item
2. Numbered list item
3. Numbered list item

#### Links

\[Text to display\](http://www.example.com)

#### Quotes

\> This is a quote.
> It can span multiple lines!

#### Images

CSS style available: `width, height, opacity`

!\[\](http://www.example.com/image.jpg)
!\[\](http://www.example.com/image.jpg | width: 200px)
!\[\](http://www.example.com/image.jpg | height: 124px | width: 80px | opacity: 0.6)

#### Tables

| Column 1 | Column 2 | Column 3 |
| -------- | -------- | -------- |
| John     | Doe      | Male     |
| Mary     | Smith    | Female   |

_Or without aligning the columns..._

| Column 1 | Column 2 | Column 3 |
| -------- | -------- | -------- |
| John | Doe | Male |
| Mary | Smith | Female |

#### Displaying code

\`var example = "hello!";\`

_Or spanning multiple lines..._

\`\`\`
var example = "hello!";
alert(example);
\`\`\`

(function(i,s,o,g,r,a,m){i\['GoogleAnalyticsObject'\]=r;i\[r\]=i\[r\]||function(){ (i\[r\].q=i\[r\].q||\[\]).push(arguments)},i\[r\].l=1\*new Date();a=s.createElement(o), m=s.getElementsByTagName(o)\[0\];a.async=1;a.src=g;m.parentNode.insertBefore(a,m) })(window,document,'script','//www.google-analytics.com/analytics.js','ga'); ga('create', 'UA-67152800-6', 'auto', { userId: '3579' } ); ga('send', 'pageview'); $(document).ready(function() { ga(function(tracker) { var clientId = tracker.get('clientId'); $('.ga-client-id').val(clientId); }); });
