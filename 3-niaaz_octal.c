#include "main.h"

/**
 * o_specifier - function to print octal
 * @format_specifier: my arguments
 * Return: always (success)
 */
int o_specifier(va_list format_specifier)
{
	int i, length = 0;
	int *buffer;
	unsigned int figure = va_arg(format_specifier, unsigned int);
	unsigned int fig = figure;

	while (figure / 8 != 0)
	{
		figure = figure / 8;
		length++;
	}
	length++;

	buffer = malloc(sizeof(int) * length);
	for (i = 0; i < length; i++)
	{
		buffer[i] = fig % 8;
		fig = fig / 8;
	}
	for (i = length - 1; i >= 0; i--)
		_putchar(buffer[i] + '0');
	free(buffer);
	return (length);
}
