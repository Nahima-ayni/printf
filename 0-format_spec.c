#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * _printf - function name
 * @format: constant char
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	char *str, next_arg;
	const char *n = format;
	int length = 0, b = 0, func_len = 0;
	va_list format_spec;

	va_start(format_spec, format);
	for (; *n != '\0'; n++)
	{
		if (*n != '%')
		{
			write(1, n, 1);
			length++;
		}
		else
		{
			n++;
			if (*n == '\0')
				break;
			else if (*n == 'c')
			{
				next_arg = va_arg(format_spec, int);
				write(1, &next_arg, 1);
				length++;
			}
			else if (*n == 's')
			{
				str = va_arg(format_spec, char *);
				write(1, str, 1);
				length++;
				str++;
			}
			else if (*n == 'd' || *n == 'i')
			{
				b = va_arg(format_spec, int);
				func_len = _integers(b);
				length += func_len;
			}
			else if (*n == '%')
			{
				write(1, "%", 1);
				length++;
			}
		}
	}
	va_end(format_spec);
	return (length);
}
