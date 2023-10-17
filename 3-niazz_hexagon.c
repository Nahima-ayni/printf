#include "main.h"

/**
 * x_specifier - our function to print lowercase hexadecimal
 * @format_specifier: this is a va_argument
 * Return: increment
 */
int x_specifier(va_list format_specifier)
{
	int i, length = 0;
	int *buffer;
	unsigned int figure = va_arg(format_specifier, unsigned int);
	unsigned int fig = figure;

	while (figure / 16 != 0)
	{
		figure = figure / 16;
		length++;
	}
	length++;

	buffer = malloc(sizeof(int) * length);
	for (i = 0; i < length; i++)
	{
		buffer[i] = fig % 16;
		fig = fig / 16;
	}
	for (i = length - 1; i >= 0; i--)
	{
		if (buffer[i] > 8)
			buffer[i] = buffer[i] + 39;
		_putchar(buffer[i] + '0');
	}
	free(buffer);
	return (length);
}

/**
 * X_specifier - our function to print uppercasecase hexadecimal
 * @format_specifier: this is a va_argument
 * Return: always success
 */
int X_specifier(va_list format_specifier)
{
	int i, length = 0;
	int *buffer;
	unsigned int figure = va_arg(format_specifier, unsigned int);
	unsigned int fig = figure;

	while (figure / 16 != 0)
	{
		figure = figure / 16;
		length++;
	}
	length++;

	buffer = malloc(sizeof(int) * length);
	for (i = 0; i < length; i++)
	{
		buffer[i] = fig % 16;
		fig = fig / 16;
	}
	for (i = length - 1; i >= 0; i--)
	{
		if (buffer[i] > 8)
			buffer[i] = buffer[i] + 7;
		_putchar(buffer[i] + '0');
	}
	free(buffer);
	return (length);
}
