#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function name
 * @format: constant char
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
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
					_string(va_arg(format_spec, char *));
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

/**
 * _string - functin to print to string
 * @str: string
 * Return: always succes
 */
int _string(char *str)
{
	int length = 0;

	if (str != NULL)
	{
		while (*str)
		{
			putchar(*str);
			length++;
			str++;
		}
	}
	return (length);
}
