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
	char _buffer[SIZE_OF_BUFFER];
	int indexbuffer = 0;
	int str_len = 0;
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
					_buffer[indexbuffer++] = (va_arg(format_spec, int));
					length++;
					break;
				case 's':
					str_len = _string(va_arg(format_spec, char *), _buffer, &indexbuffer);
					length += str_len;
					break;
				case '%':
					_buffer[indexbuffer++] = ('%');
					length++;
					break;
				default:
					_buffer[indexbuffer++] = ('%');
					length++;
					break;
			}
		}
		else
		{
			_buffer[indexbuffer++] = (*format);
			length++;
		}
		format++;
		if (indexbuffer == SIZE_OF_BUFFER)
			printbuff(_buffer, &indexbuffer);
	}
	printbuff(_buffer, &indexbuffer);
	va_end(format_spec);
	return (length);
}

/**
 * _string - functin to print to string
 * @str: string
 * Return: always succes
 */
int _string(char *str, char _buffer[], int *indexbuffer)
{
	int length = 0;
	if (str != NULL)
	{
		while (*str)
		{
			_buffer[*indexbuffer] = *str;
			(*indexbuffer)++;
			length++;
			str++;

			if (*indexbuffer == SIZE_OF_BUFFER)
				printbuff(_buffer, &indexbuffer);
		}
	}
	return (length);
}

/**
 * printbuff - output the content of _buffer
 * @_buffer: an array
 * @indexbuffer: index of array
 */
void printbuff(char _buffer[], int *indexbuffer)
{
	if (*indexbuffer > 0)
	{
		write(1, _buffer, *indexbuffer);
		*indexbuffer = 0;
	}
}
