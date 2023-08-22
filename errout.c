#include "main.h"
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
