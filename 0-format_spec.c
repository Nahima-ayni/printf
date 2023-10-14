#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - function name
 * @format: constant char
 * Return: number of characters printed
 *
 */
int _printf(const char *format, ...)
{
	char *str;
	int length = 0;
	va_list format_spec;

	va_start(format_spec, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
		if (*format == '\0')
			break;
		switch (*format)
		{
			case 'c':
				putchar(va_arg(format_spec, int));
				length++;
				break;
			case 's':
				str = va_arg(format_spec, char *);
				if (str != NULL)
				{
					while (*str)
					{
						putchar(*str);
						length++;
						str++;
					}
				}
				break;
			case '%':
				putchar('%');
				length++;
				break;
			default:
				putchar('%');
				length++;
				break;
		}
		}
	else
	{
		putchar(*format);
		length++;
	}
	format++;
	}
	va_end(format_spec);
	return (length);

}


