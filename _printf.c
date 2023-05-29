#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - is a Printf function
 * @format: format string.
 * Return: number of charachters printed.
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int x, printed = 0, printed_chars = 0;
=======
	int k, printed = 0, printed_chars = 0;
>>>>>>> cb60594bfdae23cad45989b313b2b0541e2711e4
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	return (-1);

	va_start(list, format);

<<<<<<< HEAD
	for (x = 0; format && format[n] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[x], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, x;
			width = get_width(format, x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
=======
	for (k = 0; format && format[k] != '\0'; k++)
	{
	if (format[k] != '%')
	{
	buffer[buff_ind++] = format[k];
	if (buff_ind == BUFF_SIZE)
	print_buffer(buffer, &buff_ind);
	/* write(1, &format[k], 1);*/
	printed_chars++;
	}
	else
	{
	print_buffer(buffer, &buff_ind);
	flags = get_flags(format, &k);
	width = get_width(format, &k, list);
	precision = get_precision(format, &k, list);
	size = get_size(format, &k);
	++k;
	printed = handle_print(format, &k, list, buffer,
	flags, width, precision, size);
	if (printed == -1)
	return (-1);
	printed_chars += printed;
	}
>>>>>>> cb60594bfdae23cad45989b313b2b0541e2711e4
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - it Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
