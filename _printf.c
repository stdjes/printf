#include "main.h"

void print_buff(char buffer[], int *index_buffer);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, total_char_print = 0;
	int flags, width, precision, size, index_buffer = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index_buffer++] = format[i];
			if (index_buffer == BUFF_SIZE)
				print_buff(buffer, &index_buffer);
			/* write(1, &format[i], 1); */
			total_char_print++;
		}
		else
		{
			print_buff(buffer, &index_buffer);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			i++;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			total_char_print += printed;
		}
	}

	print_buff(buffer, &index_buffer);

	va_end(list);

	return (total_char_print);
}

/**
 * print_buff - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @index_buffer: Index at which to add the next char, represents the length.
 */
void print_buff(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
		write(1, &buffer[0], *index_buffer);

	*index_buffer = 0;
}

