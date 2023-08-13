#include "main.h"
/**
* _strcmp - this function compare two strings.
* @s1: parameter is string.
* @s2: parameter is string.
* Return: resturns the defferant between first two differant chars in the
* two strings.
*/
int _strcmp(char *s1, char *s2)
{
	int i, s;

	i = 0, s = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s == 0)
	{
		s += s1[i] - s2[i];
		i++;
	}
	i--;
	return (s1[i] - s2[i]);
}
