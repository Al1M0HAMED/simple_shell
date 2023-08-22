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
		write(STDOUT_FILENO, "\nali@lostStars:~$ ", 18);
		fflush(STDIN_FILENO);
	}
}
