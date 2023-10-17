#include "main.h"

/**
 * d_specifier - function name
 * @format_specifier: va_list name
 * Return: always success
 *
 */
int d_specifier(va_list format_specifier)
{
	int next_argniaz = va_arg(format_specifier, int);
	int numbs, last_digit = next_argniaz % 10, figure, answer = 1;
	int q = 1;

	next_argniaz = next_argniaz / 10;
	numbs = next_argniaz;

	if (last_digit < 0)
	{
		_putchar('-');
		numbs = -numbs;
		next_argniaz = -next_argniaz;
		last_digit = -last_digit;
		q++;
	}
	if (numbs > 0)
	{
		while (numbs / 10 != 0)
		{
			answer = answer * 10;
			numbs = numbs / 10;
		}
		numbs = next_argniaz;
		while (answer > 0)
		{
			figure = numbs / answer;
			_putchar(figure + '0');
			numbs = numbs - (figure * answer);
			answer = answer / 10;
			q++;
		}
	}
	_putchar(last_digit + '0');
	return (q);
}

/**
 * i_specifier - function name
 * @format_specifier: va_list name
 * Return: always success
 *
 */
int i_specifier(va_list format_specifier)
{
	int next_argniaz = va_arg(format_specifier, int);
	int numbs, last_digit = next_argniaz % 10, figure, answer = 1;
	int q = 1;

	next_argniaz = next_argniaz / 10;
	numbs = next_argniaz;

	if (last_digit < 0)
	{
		_putchar('-');
		numbs = -numbs;
		next_argniaz = -next_argniaz;
		last_digit = -last_digit;
		q++;
	}
	if (numbs > 0)
	{
		while (numbs / 10 != 0)
		{
			answer = answer * 10;
			numbs = numbs / 10;
		}
		numbs = next_argniaz;
		while (answer > 0)
		{
			figure = numbs / answer;
			_putchar(figure + '0');
			numbs = numbs - (figure * answer);
			answer = answer / 10;
			q++;
		}
	}
	_putchar(last_digit + '0');
	return (q);
}
