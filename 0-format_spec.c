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
	int length = 0;
	va_list format_spec;

	va_start(format_spec, format);
	for (; *n != '\0'; n++)
	{
		if (*n != '%')
		{
			putchar(*n);
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
				putchar(next_arg);
				length++;
			}
			else if (*n == 's')
			{
				str = va_arg(format_spec, char *);
				putchar(*str);
				length++;
				str++;
			}
			else if (*n == '%')
			{
				putchar('%');
				length++;
			}
		}
	}
	va_end(format_spec);
	return (length);
}
