#include "main.h"

/**
 * _printf - function name
 * @format: constant char
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int character_printed = 0, i = 0, v;
	va_list formspec_args;
	specifier m[] = {{"%s", s_specifier}, {"%c", c_specifier},
		{"%i", i_specifier}, {"%d", d_specifier}, {"%%", mod_specifier},
		{"%b", b_specifier}, {"%x", x_specifier}, {"%X", X_specifier},
		{"%o", o_specifier}, {"%u", u_specifier}};

	va_start(formspec_args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	return (-1);

Here:
	while (format[i] != '\0')
	{
		v = 9;
		while (v >= 0)
		{
			if (m[v].format_specifier[0] == format[i] &&
					m[v].format_specifier[1] == format[i + 1])
			{
				character_printed += m[v].signature(formspec_args);
				i = i + 2;
				goto Here;
			}
			v--;
		}
		write(1, &format[i], 1);
		character_printed++;
		i++;
	}
	va_end(formspec_args);
	return (character_printed);
}
