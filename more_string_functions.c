#include "shell.h"
/**
 * _strcat - this function concatonate a string to another one.
 *
 * @dest: parameter is string.
 *
 * @src: parameter is string.
 *
 * Return: the concatonated string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}
	j = 0;
	while (*(src + j) != '\0')
	{
		*(dest + (i + j)) = *(src + j);
		j++;
	}
	*(dest + (i + j)) = '\0';
	return (dest);
}
/**
 * _strlen - calculate length of a string.
 *
 * @s: string.
 *
 * Return: int.
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*(s + i) != '\0')
	{
		i++;
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
 * array_rev - this function reverse an array elements.
 *
 * @a: is pointer to array.
 *
 * @n: is integer.
 *
 * Return: nothing.
 */
void array_rev(char *a, int n)
{
	int i, j, l, first_e, last_e;

	if (n > 0)
	{
		l = n / 2;
		i = 0, j = (n - 1);
		while (i != l)
		{
			last_e = a[j];
			first_e = a[i];
			a[j] = first_e;
			a[i] = last_e;
			j--;
			i++;
		}
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

