
0x01. C - ls
 By Wilfried Hennuyer, Software Engineer at Holberton School
 Weight: 1
 Project over - took place from May 4, 2022 to May 11, 2022 - you're done with 0% of tasks.
 An auto review will be launched at the deadline
In a nutshell…
Auto QA review: 0.0/35 mandatory
Altogether:  0.0%
Mandatory: 0.0%
Calculation:  0.0%  == 0.0%
Concepts
For this project, students are expected to look at this concept:

[EYNTK] Create your own ls
Resources
Read or watch:

Concept pages linked to this project
man ls
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
How does ls work?
What are all the functions used by ls?
Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
No more than 5 functions per file
All your header files should be include guarded
Valgrind should show 0 memory leak and 0 error
Unless specified otherwise, your program must have the exact same output as ls as well as the exact same error output - except for alignment.
Allowed Functions and System Calls
opendir (man 3 opendir)
readdir (man 3 readdir)
closedir (man 3 closedir)
exit (man 3 exit)
free (man 3 free)
lstat (man 2 lstat)
malloc (man 3 malloc)
perror (man 3 perror)
write (man 2 write)
printf (man 3 printf)
sprintf (man 3 sprintf)
fprintf (man 3 fprintf)
readlink (man 2 readlink)
ctime (man 3 ctime)
getpwuid (man 3 getpwuid)
getgrgid (man 3 getgrgid)
errno (man 3 errno)
More Info
Compilation
Your program will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hls
Every task depends on the previous ones. We strongly encourage you to read the entire project and think about the way you are going to design your entire ls before starting. (This is actually something you should do all the time :)).

Testing
Your program should give the same result as the real ls:

$ ls test
abc  BCD  file  file2  file3  folder1  folder2  folder3
$ ./hls test
abc  BCD  file  file2  file3  folder1  folder2  folder3
$ ls -1
abc
BCD
file
file2
file3
folder1
folder2
folder3
hls
$ ./hls -1
abc
BCD
file
file2
file3
folder1
folder2
folder3
hls
$
Details
For all tasks of this project, unless explicitly said otherwise:

You don’t have to worry about the spacing
You don’t have to worry about the sorting
Tasks
0. Let's start with something simple!
mandatory
Score: 0.00% (Checks completed: 0.00%)
Create a program that lists the content of the current directory.

Usage : hls
wilfried@~$ ls
abc  file  File2  file3  folder1  Folder2  folder3  hls
wilfried@~$ ./hls
abc  file  File2  file3  folder1  Folder2  folder3  hls
wilfried@~$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x01-ls
    
1. Maybe some parameters?
mandatory
Score: 0.00% (Checks completed: 0.00%)
Your program should now take one or more file or directory names as parameters.

Usage : hls [FILE]...

Errors must be printed the same way than ls does:

In stderr
Starting by <program>: (<program> being argv[0])
No such file or directory, Permission denied, etc…
Don’t forget the exit value
wilfried@~$ ls test
abc  file  File2  file3  folder1  Folder2  folder3
wilfried@~$ ./hls test
abc  file  File2  file3  folder1  Folder2  folder3
wilfried@~$ ./hls test/folder1/ test
test:
abc  file  File2  file3  folder1  Folder2  folder3

test/folder1/:
folder1-1  folder1-2  folder1-3
/simple_ls$ ./hls test/random
./hls: cannot access test/random: No such file or directory
wilfried@~$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x01-ls
    
2. What about options?
mandatory
Score: 0.00% (Checks completed: 0.00%)
Implement the -1 option.

Usage : hls [-1] [FILE]...

For the rest of the project, an option will be identified by a command-line argument starting with the character - (like ls).

wilfried@~$ ls test -1
abc
file
File2
file3
folder1
Folder2
folder3
wilfried@~$ ./hls test -1
abc
file
File2
file3
folder1
Folder2
folder3
wilfried@~$
Pay attention to “edge cases”: you should be able to handle multiple options, in any order.

Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x01-ls
    
3. Hidden files
mandatory
Score: 0.00% (Checks completed: 0.00%)
Implement the -a option.

Usage : hls [-a1] [FILE]...

wilfried@~$ ls -a test
.  ..  abc  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
wilfried@~$ ./hls -a test
.  ..  abc  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
wilfried@~$ ./hls -a test/folder1
.  ..  folder1-1  folder1-2  folder1-3
wilfried@~$  
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x01-ls
    
4. Almost all
mandatory
Score: 0.00% (Checks completed: 0.00%)
Implement the -A option.

Usage : hls [-A] [FILE]...

wilfried@~$ ls -A test
abc  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
wilfried@~$ ./hls -A test
abc  file  File2  file3  folder1  Folder2  folder3  .hidden1  .hidden2  ..hidden3
wilfried@~$ ./hls -A test/folder1
folder1-1  folder1-2  folder1-3
wilfried@~$
Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x01-ls
    
5. More details
mandatory
Score: 0.00% (Checks completed: 0.00%)
Implement the -l option.

Usage : hls [-l] [FILE]...

wilfried@~$ ls -l test
total 12
-rw-rw-r-- 1 wilfried wilfried    0 May  8 00:19 abc
-rw-rw-r-- 1 wilfried wilfried    0 Apr 18 14:04 file
-rw-rw-r-- 1 wilfried wilfried    0 Apr 18 14:04 File2
-rw-rw-r-- 1 wilfried wilfried    0 Apr 18 14:04 file3
drwxrwxr-x 5 wilfried wilfried 4096 Apr 30 15:22 folder1
drwxrwxr-x 2 wilfried wilfried 4096 May  7 15:36 Folder2
drwxrwxr-x 3 wilfried wilfried 4096 May  7 15:37 folder3
wilfried@~$ ./hls -l test
-rw-rw-r-- 1 wilfried wilfried    0 May  8 00:19 abc
-rw-rw-r-- 1 wilfried wilfried    0 Apr 18 14:04 file
-rw-rw-r-- 1 wilfried wilfried    0 Apr 18 14:04 File2
-rw-rw-r-- 1 wilfried wilfried    0 Apr 18 14:04 file3
drwxrwxr-x 5 wilfried wilfried 4096 Apr 30 15:22 folder1
drwxrwxr-x 2 wilfried wilfried 4096 May  7 15:36 Folder2
drwxrwxr-x 3 wilfried wilfried 4096 May  7 15:37 folder3
wilfried@~$
You might notice the total 12 in the first line of ls -l. You can ignore this value for this exercise.

Be careful: sometimes user names or group names are not defined

Repo:

GitHub repository: holbertonschool-system_linux
Directory: 0x01-ls
    
Copyright © 2022 Holberton Inc, All rights reserved.
