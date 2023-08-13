#include "main.h"
/**
*
*
*
*/
void shell_loop(void)
{
	int continue_loop = 1;
	size_t i = 1024;
	char *args[10], *cmd, *buff = NULL;

	while (continue_loop)
	{
		write(1, "ali@lostStars:~$ ", 17);
		getline(&buff, &i, stdin);

		cmd = strtok(buff, " \n");
		if (cmd != NULL)
		{
			int arg_count = 0;
			while (arg_count < 10)
			{
				args[arg_count] = strtok(NULL, " \n");
				if (args[arg_count] == NULL)
					break;
				arg_count++;
			}
			args[arg_count] = NULL;
			continue_loop = _excute(cmd, args);
		}
	}
	free(buff);
}
