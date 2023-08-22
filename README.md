# Simple Shell Project

This is a simple shell program written in C. The shell provides a basic command-line interface that can execute commands, handle built-in commands, and search for executables in the PATH.

## Features

- Supports basic command execution.
- Handles built-in commands such as `exit`, `clear`, and `env`.
- Searches for executable commands in the PATH.
- Handeles EOF (end of file) Ctrl+D.
- Handles SIGINT signal (Ctrl+C) gracefully.
- Displays a prompt with the current working directory.

## About the Project

This project is a part of the curriculum at ALX Holberton School, as a final project for sprint one. It represents a significant milestone in our learning journey at ALX, showcasing the skills and knowledge we've gained so far.

As a student at ALX Holberton School, I'm a member of cohort 16. While this project was a collaborative effort within our group, I took the initiative to lead the implementation of various features.

## Getting Started

To compile and run the simple shell program, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Compile the code using a C compiler (e.g., GCC): `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
4. Run the compiled program: `./hsh`

## testing

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

## Usage

Once the shell is running, you can enter commands just like in a regular shell. Built-in commands are supported:

- `exit`: Terminate the shell.
- `clear`: Clear the screen.
- `env`: Display environment variables.

External commands are executed by providing the full path or command name (searched in the PATH).

```shell
:) ls
README.md AUTHORS
:) pwd
/home/user
:) htbn_ds
./hsh: 1: htbn_ds: not found
:( ls -la
-rw-r--r-- 1 ali ali   94 Aug 22 19:42 AUTHORS
-rw-r--r-- 1 ali ali 1648 Aug 22 19:53 README.md
:) exit
