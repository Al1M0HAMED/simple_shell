#include "main.h"
/**
* sigint_handler - this function handels ^C.
* @_signal: .
* ## 100053370433155 ##
*/
void sigint_handler(int _signal)
{
	if (_signal == SIGINT)
	{
		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "\n:) ", 4);
			fflush(STDIN_FILENO);
		}
	}
}
