#include "main.h"
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
