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
	int length = 0, indexbuffer = 0;
	char _buffer[SIZE_OF_BUFFER];
	va_list format_spec;

	va_start(format_spec, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				_buffer[indexbuffer++] = va_arg(format_spec, int);
			else if (*format == 's')
				length += _string(va_arg(format_spec, char *), _buffer, &indexbuffer);
			else if (*format == '%')
				_buffer[indexbuffer++] = '%';
			else
				_buffer[indexbuffer++] = '%';
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
 * @_buffer: arrays
 * @indexbuffer: index of arrays
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
				printbuff(_buffer, indexbuffer);
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
