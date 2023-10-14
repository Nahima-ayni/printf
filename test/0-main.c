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
	char c = 'n';
	char *str = "nahima";

	_printf("%c", c);
	_printf("%s", str);
	_printf("%%");

	return 0;
}
