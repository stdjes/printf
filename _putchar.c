#include "main.h"
#include <unistd.h>

/**
 * _putchar - a function that writes the character c
 * to the standard output
 *
 * @c: The character to be printed
 * Return: On success 1, returns -1 on error.
 * Description: _putchar is a customr function that
 * uses a local buffer of 1024 to call write function.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
