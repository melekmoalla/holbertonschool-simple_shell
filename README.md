<h1> Simple Shell</h1>

- this projet is just I small simple shell
- This is a simple UNIX shell program built in C. Supported built-in commands are listed below, otherwise this shell is capable of searching for and executing programs on the PATH.

<h3> Objectives</h3>

- Learn Unix Shell.
- Learn Unix Parent and Child Processes.
- Learn Unix Input and Output redirections.
- Learn Unix fork(), exec(), wait() system calls.
- Implement a Simple Shell Application using Unix system calls.

# Instructions</h3>


- You must program a mini `Unix shell`, try to focus on something simple like [BusyBox](https://en.wikipedia.org/wiki/BusyBox).
- This interpreter must display at least a simple `$` and wait until you type a command line which will be validated by pressing enter.
- The `$` will be shown again only once the command has been completely executed.
- The command lines are simple, you will not have pipes, redirection or any other advanced functions.
- You must manage the errors, by displaying a message adapted to the error output.
- You must implement the following commands:
  - echo
  - cd
  - ls
  - pwd
  - cat
  - cp
  - rm
  - mv
  - mkdir
  - exit
- You must manage the program interruption `Ctrl + D`.
- The project has to be written in a compiled language like C

This project will help you learn about:

- Shell
- Operating systems services
- Command-line interfaces
- Unix system
- Process creation and synchronization
- Commands syntax
- Scripting language


```
```

# Test Compilation

<p> Created and tested with Ubuntu 14.04 LTS

Compiled with GCC 4.8.4 with flags: -Wall -Werror -Wextra -pedantic -std=gnu89</p>

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

# Testing

<p> Your shell should work like this in interactive mode: </p>

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

# Usage

```
peytonbrsmith@penguin:~/simple_shell$ ./a.out
($) /bin/ls
a.out  builtins.c  execute.c  holberton.h  parse.c  path.c  _printf.c  README.md  simpshell.c  strtools2.c  strtools.c
($) ls -la /usr/
total 0
drwxr-xr-x 1 root root    80 Jul 21 23:26 .
drwxrwxrwx 1 root root   172 Nov  4 11:54 ..
drwxr-xr-x 1 root root 22188 Nov  4 11:53 bin
drwxr-xr-x 1 root root    10 Oct 27 11:00 games
drwxr-xr-x 1 root root  2262 Nov  3 18:50 include
drwxr-xr-x 1 root root  1880 Nov  3 19:34 lib
drwxr-xr-x 1 root root     6 Jul 21 23:26 lib64
drwxr-xr-x 1 root root    72 Jul 21 00:26 local
drwxr-xr-x 1 root root  4122 Nov  3 19:32 sbin
drwxr-xr-x 1 root root  2592 Nov  4 11:53 share
drwxr-xr-x 1 root root     0 May  2  2020 src
($) pwd
/home/peytonbrsmith/simple_shell
($) cd /home/
($) pwd
/home
($) ls
peytonbrsmith
($) exit
```


# Project Status

Checked using Valgrind. No known memory leaks or bugs.

Currently there are no plans to continue working on the simple shell after completion of the project.

# Author

By Melek Moalla:<br>
https://github.com/melekmoalla