#include "main.h"

/**
 * u_specifier - our function that prints positive numbers
 * @format_specifier: my function
 * Return: always (success)
 */
int u_specifier(va_list format_specifier)
{
	int number = va_arg(format_specifier, int);
	int uNum, lastOne = number % 10, digit, exp = 1;
	int i = 1;

	number = number / 10;
	uNum = number;

	if (lastOne < 0)
	{
		_putchar('-');
		uNum = -uNum;
		number = -number;
		lastOne = -lastOne;
		i++;
	}
	if (uNum > 0)
	{
		while (uNum / 10 != 0)
		{
			exp = exp * 10;
			uNum = uNum / 10;
		}
		uNum = number;
		while (exp > 0)
		{
			digit = uNum / exp;
			_putchar(digit + '0');
			uNum = uNum - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(lastOne + '0');
	return (i);
}
