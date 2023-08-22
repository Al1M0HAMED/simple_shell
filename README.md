# Simple Shell Project

This is a simple shell program written in C. The shell provides a basic command-line interface that can execute commands, handle built-in commands, and search for executables in the PATH.

## Features

- Supports basic command execution.
- Handles built-in commands such as `exit`, `clear`, and `env`.
- Searches for executable commands in the PATH.
- Handles SIGINT signal (Ctrl+C) gracefully.
- Displays a prompt with the current working directory.

## Getting Started

To compile and run the simple shell program, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Compile the code using a C compiler (e.g., GCC): `gcc -o shell main.c`
4. Run the compiled program: `./shell`

## Usage

Once the shell is running, you can enter commands just like in a regular shell. Built-in commands are supported:

- `exit`: Terminate the shell.
- `clear`: Clear the screen.
- `env`: Display environment variables.

External commands are executed by providing the full path or command name (searched in the PATH).

```shell
$ ls
file1.txt file2.txt
$ pwd
/home/user
$ exit
