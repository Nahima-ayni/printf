#include "main.h"

/**
 *d_specifier - prints when %d is used
 *@format_specifier: the string passed
 *Return: always success
 */
int d_specifier(va_list format_specifier)
{
	int number = va_arg(format_specifier, int);
	int figure, lastint = number % 10, digit, exp = 1;
	int i = 1;
	char digitint, last;

	number = number / 10;
	figure = number;

	if (lastint < 0)
	{
		write(1, "-", 1);
		figure = -figure;
		number = -number;
		lastint = -lastint;
		i++;
	}
	if (figure > 0)
	{
		while (figure / 10 != 0)
		{
			exp = exp * 10;
			figure = figure / 10;
		}
		figure = number;
		while (exp > 0)
		{
			digit = figure / exp;
			digitint = digit + '0';
			write(1, &digitint, 1);
			figure = figure - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	last = lastint + '0';
	write(1, &last, 1);
	i++;
	return (i);
}

/**
 *i_specifier - prints when %d is used
 *@format_specifier: the string passed
 *Return: always success
 */
int i_specifier(va_list format_specifier)
{
	int number = va_arg(format_specifier, int);
	int figure, lastint = number % 10, digit, exp = 1;
	int i = 1;
	char digitint, last;

	number = number / 10;
	figure = number;

	if (lastint < 0)
	{
		write(1, "-", 1);
		figure = -figure;
		number = -number;
		lastint = -lastint;
		i++;
	}
	if (figure > 0)
	{
		while (figure / 10 != 0)
		{
			exp = exp * 10;
			figure = figure / 10;
		}
		figure = number;
		while (exp > 0)
		{
			digit = figure / exp;
			digitint = digit + '0';
			write(1, &digitint, 1);
			figure = figure - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	last = lastint + '0';
	write(1, &last, 1);
	i++;
	return (i);
}
