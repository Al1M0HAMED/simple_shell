#include "main.h"
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
		prompt(0);
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
			b = built(command[0], buffer, &child_exit_status, &continue_loop);
			command[c] = NULL;
			if (b)
				child_exit_status = _excutev(command, buffer, argv[0], continue_loop);
		}
	}
	free(buffer);
	return (child_exit_status);
}
/**
 * built - this function search for a built in command.
 * @command: is the command.
 * @buffer: is the buffer.
 * @e: is the error status.
 * @c: is the number of excuted times.
 * Return: 1 if faild 0 if success.
 */
int built(char *command, char *buffer, int *e, int *c)
{
	int ee = *e, i = 0;

	if (_strcmp(command, "exit") == 0)
	{
		free(buffer);
		_exit(ee);
	}
	if (_strcmp(command, "clear") == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
		*c = *c + 1;
		return (0);
	}
	if (_strcmp(command, "env") == 0)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			if (i)
				write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			i++;
		}
		return (0);
	}
	return (1);
}
#include "main.h"
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
			write(STDOUT_FILENO, "ali@lostStars:~$ ", 17);
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
