#include "main.h"
/**
*
*
*
*/
int _excute(char *cmd, char **args)
{
	int i;
	pid_t pid;
	char pathname[30] = "/bin/";
	char exit_cmd[] = "exit";
	char clear_cmd[] = "clear";
	char *argv[11] = {NULL};

	if (_strcmp(cmd, exit_cmd) == 0)
		return (0);
	if (_strcmp(cmd, clear_cmd) == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[2J", 7);
		return (1);
	}

	argv[0] = _strcat(pathname, cmd);
	for (i = 0; args[i] != NULL && i < 10; i++)
	{
		argv[i + 1] = args[i];
	}
	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		_exit(1);
	}
	else if (pid > 0)
	{
		int status;
		waitpid(pid, &status, 0);
	}
	return (1);
}
