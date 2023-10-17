#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_OF_BUFFER 1024

/**
 * struct modify - A structure representing a format specifier and
 * its corresponding function.
 *
 * @format_specifier: A string representing the format specifier
 * (e.g., "%s", "%d").
 * @signature: A function pointer to the function that handles this
 * format specifier.
 */
typedef struct modify
{
	char *format_specifier;
	int (*signature)();
} specifier;

int o_specifier(va_list format_specifier);
int b_specifier(va_list format_specifier);
int X_specifier(va_list format_specifier);
int x_specifier(va_list format_specifier);
int _printf(const char *format, ...);
int s_specifier(va_list format_specifier);
int c_specifier(va_list format_specifier);
int mod_specifier(void);
int i_specifier(va_list format_specifier);
int d_specifier(va_list format_specifier);
int _slength(char *len);
int _clength(char *clen);
int _putchar(char c);
int u_specifier(va_list format_specifier);

#endif
