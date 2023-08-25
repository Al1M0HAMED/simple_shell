#include "shell.h"
/**
* built - this function search for a built in command.
* @command: is the command.
* @buffer: is the buffer.
* @argv: is the prgram name.
* @c: is the number of excuted times.
* Return: 1 if faild 0 if success.
*/
int built(char *command[], char *buffer, char *argv, int *c)
{
	int i = 0;

	if (_strcmp(command[0], "exit") == 0)
	{
		free(buffer);
		_exit(0);
	}
	if (_strcmp(command[0], "clear") == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
		*c = *c + 1;
		return (0);
	}
	if (_strcmp(command[0], "env") == 0)
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
	if (_strcmp(command[0], "cd") == 0)
	{
		_cd(command, argv, c);
		return (0);
	}
	return (1);
}
/**
 * _cd - this is a implemantation of built in cd command.
 * @command: parametar is array of strings.
 * @argv: is the program name.
 * @n: is the time of excution of the program.
 */
void _cd(char *command[], char *argv, int *n)
{
	struct stat buffer;
	char *str;

	if (command[1] == NULL)
	{
		if (_getenv("HOME") != NULL)
		{
			setenv("PWD", _getenv("HOME"), 1);
			chdir(_getenv("HOME"));
		}
		return;
	}
	else if (strcmp(command[1], "-") == 0)
	{
		if (_getenv("OLDPWD") == NULL)
			return;
		str = _strdup(_getenv("OLDPWD"));
		setenv("PWD", str, 1);
		chdir(str);
		free(str);
	}
	else
	{

		str = _strdup(_getenv("PWD"));
		_strcat(str, "/");
		_strcat(str, command[1]);
		if (stat(str, &buffer) == 0 && S_ISDIR(buffer.st_mode))
		{
			setenv("PWD", str, 1);
			chdir(str);
		}
		else
			cd_error(n, command, argv);
	}
}
/**
 * cd_error - print error for cd.
 * @command: parametar is array of strings.
 * @argv: is the program name.
 * @i: is the time of excution of the program.
 */
void cd_error(int *i, char *command[], char *argv)
{
	int n = *i;

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, _itoa(n), _strlen(_itoa(n)));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command[0], _strlen(command[0]));
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, command[1], _strlen(command[1]));
	write(STDERR_FILENO, "\n", 1);
}
