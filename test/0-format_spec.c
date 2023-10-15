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
	char *str, next_arg, const char *c, int length = 0, i;
	va_list format_spec;

	va_start(format_spec, format);
	for (*c = format; *c != '\0'; c++)
	{
		if (*c != '%')
		{
			putchar(*c);
			length++;
		}
		else
		{
			c++;
			if (*c == '\0')
				break;
		else if (*c == 'c')
		{
			next_arg = va_arg(format_spec, int);
			putchar(next_arg);
			length++;
		}
		else if (*c == 's')
		{
			*str = va_arg(format_spec, char *);
			for (i = 0; str[i] != '\0'; i++)
			{
				putchar(str[i]);
				length++;
			}
		}
		else if (*c == '%')
		{
			putchar('%');
			length++;
		}
	}
	va_end(format_spec);
	return (length);
}
