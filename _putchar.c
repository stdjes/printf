#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to standard out.
 * @c: The character to be written out
 *
 * Return: On success 1. On error, -1 is returned,
 * Description: this _putchar  function uses a local buffer
 * to call write as little s
 * The buffer is flushed when it reaches its capacity
 * or when a special flag value (-1) is passed.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int buffer_index;

	if (c == -1 || buffer_index >= 1023)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}

	if (c != -1)
	{
		buffer[buffer_index] = c;
		buffer_index++;
	}

	return (1);
}
