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
	int i = 0;
	int print;
	char *str;
	int length = 0;
	va_list format_spec;

	va_start(format_spec, format);

	while (format && format[i])
	{
		print = 1;
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(format_spec, int));
				break;
			case 's':
				str = va_arg(format_spec, char *);
				if (str == NULL)
				{
					return (0);
				}
				printf("%s", str);
				break;
			case '%':
				printf("%%");
				break;
			default:
				print = 0;
		}
		
		if (print)
			length = strlen(format);
		i++;
	}
		va_end(format_spec);
		printf("\n");
		return (length);
	
}

