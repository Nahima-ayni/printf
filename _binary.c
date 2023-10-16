#include "main.h"

/**
 *b_specifier - prints binary
 *@format_specifier: an array
 *Return: always success
 */
int b_specifier(va_list format_specifier)
{
	int num = va_arg(format_specifier, int);
	int binary[32];
	int i = 0, j;
	char digit_char;

	if (num == 0)
	{
		write(1, "0", 1);
		return (0);
	}

	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		digit_char = binary[j] + '0';
		write(1, &digit_char, 1);
	}
	return (1);
}
