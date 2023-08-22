#include "main.h"
/**
 * _strcat - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */
int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}
/**
 * _strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
/**
 *  array_rev - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void(Reverse Array)
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
/**
 * _strcmp - this function compare two strings.
 *
 * @s1: parameter is string.
 *
 * @s2: parameter is string.
 *
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

