# Simple Shell Project
<p align="center">
  <em>"UNIX is basically a simple operating system, but you have to be a genius to understand the simplicity"</em>
</p>
<p align="center">
  <img src="https://miro.medium.com/v2/resize:fit:1400/1*WqxZ99tyXrI3aIYW8lLoHA.png" alt="logo">
</p>

### Introduction

This repository is a [Holberton School](https://www.holbertonschool.com/) and [ALX](https://www.alxafrica.com/) Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne  , in **C**, using a limited number of standard library functions, So Instead i used my own function that i rewrited over the past three month [Here](https://github.com/Al1M0HAMED/alx-low_level_programming)

## Features

- supports cd and upadate OLDPWD and PWD to gave correct `pwd` and `ls`.
- Supports basic command execution.
- Handles built-in commands such as `exit`, `clear`, and `env`, and `cd`.
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
```shell
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
````

## Usage

Once the shell is running, you can enter commands just like in a regular shell. Built-in commands are supported:
- `cd`: navigate the system.
- `exit`: Terminate the shell.
- `clear`: Clear the screen.
- `env`: Display environment variables.

External commands are executed by providing the full path or command name (searched in the PATH).

```shell
:) ls
README.md AUTHORS
:) /bin/ls
README.md AUTHORS
:) pwd
/home/user
:) cd /path/to/directory
:) pwd
/path/to/directory
:) dsasda
./hsh: 1: dsasda: not found
:( cd ..
:) ls -la
total 3
drwxr-xr-x 2 user user 4096 Aug 26 10:00 .
drwxr-xr-x 4 user user 4096 Aug 26 09:58 ..
-rw-r--r-- 1 user user  158 Aug 26 10:00 file.txt
:) exit
````
### List of functions and system calls i could use
List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    fork (man 2 fork)
    free (man 3 free)
    fstat (man 2 fstat)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    kill (man 2 kill)
    lstat (man 2 lstat)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (man 2 stat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
    _exit (man 2 _exit)

## Custom Function (Recreation of Standard Function in C)

Here's a detailed overview of the key functions in this project:

## Functions

### built_in_commands.c

- `built`: Handles built-in commands such as `exit`, `clear`, `env`, and `cd`.
- `_cd`: Implements the built-in `cd` command to change the current working directory.
- `cd_error`: Displays error messages for the `cd` command.

### string_functions.c

- `intlen`: Determines the length of an integer.
- `_itoa`: Converts an integer to a string.
- `_strcpy`: Copies a string.
- `_strncmp`: Compares a specified number of characters in two strings.

### more_string_functions.c

- `_strcat`: Concatenates two strings.
- `_strlen`: Calculates the length of a string.
- `_strdup`: Duplicates a string.
- `array_rev`: Reverses the order of elements in an array.
- `_strcmp`: Compares two strings.

### path.c

- `check_cmd`: Checks if a command exists in the PATH.
- `combine`: Combines a command with its full path.
- `helper`: Helper function to check command existence.
- `_getenv`: Retrieves the value of an environment variable.

### shell.c

- `main`: Main function that runs the shell.
- `prompt`: Displays the shell prompt.
- `_excutev`: Executes a command using `execve`.
- `_errout`: Prints error messages for command execution.

### shell.h

- Header file containing function prototypes and macros.

## AUTHORS

* Ali Mohamed [Facebook](https://www.facebook.com/profile.php?id=100053370433155)
