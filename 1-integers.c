#include <unistd.h>
#include "main.h"

/**
 *_integer - prints integers
 *@a: value passed
 *Return: always success
 */
int _integers(int a)
{
	int length = 0;
	
	write(1, &a, 1);
	length++;

	return (length);
}
