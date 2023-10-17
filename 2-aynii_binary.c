#include "main.h"

/**
 *b_specifier - prints binary
 *@format_specifier: a  string
 *Return: always success
 */
int b_specifier(va_list format_specifier)
{
	unsigned int nums = va_arg(format_specifier, unsigned int);
	unsigned int binary[32];
	int i = 0, length = 0;
	char digit_char;

	if (nums == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (nums > 0)
	{
		binary[i] = nums % 2;
		nums = nums / 2;
		i++;
	}

	length = i;
	for (i = length - 1; i >= 0; i--)
	{
		digit_char = binary[i] + '0';
		write(1, &digit_char, 1);
	}

	return (length);
}
