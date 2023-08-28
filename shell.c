#include "shell.h"
/**
* main - this is simple shell.
*
* description: this program prompt a $ with waiting for you enter a command and
* then search if it builtin if not search at PATH if it exist it excute
* it for it else it exit with error message.
*
* @argc: is the number of arguments passed.
*
* @argv: is a array of arguments strings passed.
*
* Return: Return 0 in success 2 when exit with error 127 when the
* command is not found.
*
* l_ali.m0hamed_l
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	int child_exit_status = 0, continue_loop = 1, c, b;
	size_t buffer_size = BUFSIZE;
	char *command[11], *buffer = NULL, *cmd;
	ssize_t bytes_read;

	signal(SIGINT, sigint_handler);
	for (b = 1; continue_loop; continue_loop++)
	{
		if (!child_exit_status)
			prompt(0);
		else
			prompt(6);
		bytes_read = getline(&buffer, &buffer_size, stdin);
		if (bytes_read == EOF)
		{
			prompt(1);
			break;
		}
		buffer[bytes_read - 1] = '\0', cmd = strtok(buffer, " \n");
		if (cmd != NULL)
		{
			c = 0;
			command[c++] = cmd;
			for (; c < 11; c++)
			{
				command[c] = strtok(NULL, " \n");
				if (command[c] == NULL)
				break;
			}
			if (strcmp(command[0], "exit") == 0)
				free(buffer), exit(child_exit_status);
			b = built(command, buffer, argv[0], &continue_loop);
			child_exit_status = b;
			command[c] = NULL;
			if (b)
				child_exit_status = _excutev(command, buffer, argv[0], continue_loop);
		}
	}
	free(buffer);
	return (child_exit_status);
}
/**
 * prompt - this function prompt the normal shell prombt :).
 * @status: this int will decide what prompt should be printed.
 * mohamed37222721@gmail.com
 */
void prompt(int status)
{
	if (!status)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(STDIN_FILENO);
			write(STDOUT_FILENO, ":) ", 3);
		}
	}
	else if (status == 6)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(STDIN_FILENO);
			write(STDOUT_FILENO, ":( ", 3);
		}
	}
	else if (status == 2)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
	}
	else
	{
		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			fflush(STDIN_FILENO);
		}
	}
}
/**
* _excutev - this function excute a program.
* @arguments: is the args passed to the shell.
* @buffer: is the buffer.
* @argv: is the shell program name to produce error.
* @c: is the number of excution count.
* Return: the child exit status.
* ## 100008665448159 ##
*/
int _excutev(char *arguments[], __attribute__((unused)) char *buffer,
		char *argv, int c)
{
	pid_t process_id;
	int child_exit_status = 0;
	char *cmd;

	cmd = check_cmd(arguments[0]);
	if (cmd != NULL)
	{
		process_id = fork();
		if (process_id == -1)
		{
			perror("Error");
			_exit(-1);
		}
		if (process_id == 0)
		{
			if (execve(cmd, arguments, environ) == -1)
			perror("Error");
			_exit(127);
		}
		else if (process_id > 0)
		{
			int status;

			waitpid(process_id, &status, 0);
			if (WIFEXITED(status))
				child_exit_status = WEXITSTATUS(status);
			free(cmd);
		}
	}
	else
	{
		_errout(argv, c, arguments[0]);
		child_exit_status = 127;
	}
	return (child_exit_status);
}
/**
* _errout - this function prints error message.
* @argv: is the program name.
* @argc: is the number of commands from the shell did excute a cmd.
* @command: is the command the has not been found.
* Return: error.
*/
int _errout(char *argv, int argc, char *command)
{
	char *c = _itoa(argc);

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, c, _strlen(c));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
	free(c);
	return (127);
}
