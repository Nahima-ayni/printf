#include "main.h"

/**
 * _printf - function name
 * @format: constant char
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int character_printed = 0, i = 0;
	size_t v;
	va_list formspec_args;
	specifier m[] = {{"%s", s_specifier}, {"%c", c_specifier},
	{"%i", i_specifier},{"%d", d_specifier}, {"%%", mod_specifier},
	{"%b", b_specifier}};

	va_start(formspec_args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			for (v = 0; v < sizeof(m) / sizeof(m[0]); v++)
			{
				if (format[i + 1] == *m[v].format_specifier)
				{
					character_printed += m[v].signature(formspec_args);
					i++;
					break;
				}
			}
		}
		else
		{
			write(1, &format[i], 1);
			character_printed++;
		}
		i++;
	}
	va_end(formspec_args);
	return (character_printed);
}
