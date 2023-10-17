#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_OF_BUFFER 1024

typedef struct modify
{
	char *format_specifier;
	int (*signature) ();
}specifier;

int b_specifier(va_list format_specifier);
int _printf(const char *format, ...);
int s_specifier(va_list format_specifier);
int c_specifier(va_list format_specifier);
int mod_specifier(void);
int i_specifier(va_list format_specifier);
int d_specifier(va_list format_specifier);
int _slength(char *len);
int _clength(char *clen);
int _putchar(char c);
#endif
