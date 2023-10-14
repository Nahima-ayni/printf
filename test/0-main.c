#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Return: always success
 *
 */
int main(void)
{
	int n = 67;
	char c = 'n';
	char *str = "nahima";

	_printf("%c\n", n);
	_printf("%c\n", c);
	_printf("%s\n", str);
	_printf("%%\n");

	return 0;
}
