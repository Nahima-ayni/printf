#include "main.h"

/**
 * _slength - function name for string length
 * @len: length of the string
 * Return: always success
 */
int _slength(char *len)
{
	int i = 0;

	while (len[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _clength - function name for character name
 * @clen: character length
 * Return: always success
 */
int _clength(char *clen)
{
	int c = 0;

	while (clen[c] != '\0')
	{
		c++;
	}
	return (c);
}
