#include "main.h"

/**
 * _printf - function name
 * @format: constant char
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int character_printed = 0, v, i = 0, spec_found = 0;
	va_list form_specifiers;
	specifier m[] = {
		{"%s", s_specifier},
		{"%c", c_specifier},
		{"%i", i_specifier}, {"%d", d_specifier},
		{"%%", mod_specifier},
	};

	va_start(form_specifiers, format);
	while (*format)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			for (v = 0; v < (int)(sizeof(m) / sizeof(m)[0]); v++)
			{
				if (format[i + 1] == *m[v].format_specifier)
				{
					character_printed += m[v].signature(form_specifiers);
					i++;
					spec_found = 1;
					break;
				}
			}
			if (spec_found == 0)
			{
				write(1, &format, 1);
				character_printed++;
			}
			else
			{
				write(1, &format, 1);
				character_printed++;
			}
		}
		i++;
	}
	va_end(form_specifiers);
	return (character_printed);
}
