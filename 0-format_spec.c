#include "main.h"

/**
 * c_specifier - funcion name
 * @format_specifier: our va_list name
 * Return: always success
 */
int c_specifier(va_list format_specifier)
{
	char character;

	character = va_arg(format_specifier, int);

	write(1, &character, 1);
	return (1);
}

/**
 * mod_specifier - function name
 * Return: always success
 */
int mod_specifier(void)
{
	char c = 37;

	write(1, &c, 1);
	return (1);
}

/**
 * s_specifier - our function name
 * @format_specifier: string
 * Return: always success
 */
int s_specifier(va_list format_specifier)
{
	char *str;
	int i;
	int length = 0;

	str = va_arg(format_specifier, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _slength(str);
		for (i = 0; i < length; i++)
			write(1, &str[i], 1);
		return (length);
	}
	else
	{
		length = _slength(str);
		for (i = 0; i < length; i++)
			write(1, &str[i], 1);
		return (length);
	}
}
