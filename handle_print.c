#include "main.h"
/**
 * handle_print - this Prints the provided argument based on its type
 * @fmt112: this is The formatted string used to print the arguments
 * @list: ths is the list of arguments
 * @ind: an indicator var
 * @buffer: this is a Buffer array to handle print.
 * @flags:they are able to calculate active flags
 * @width: for gettng width.
 * @precision: this is Precision specifier
 * @size: Size specifie coder
 * Return: 1 or 2;
 */
int handle_print(const char *fmt112, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int k, unknow_len = 0, printed_chars = -1;
	fmt_t112 fmt112_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (k = 0; fmt112_types[k].fmt112 != '\0'; k++)
		if (fmt112[*ind] == fmt112_types[k].fmt112)
			return (fmt112_types[k].fn112(list, buffer, flags, width, precision, size));

	if (fmt112_types[k].fmt112 == '\0')
	{
		if (fmt112[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt112[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt112[*ind] != ' ' && fmt112[*ind] != '%')
				--(*ind);
			if (fmt112[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt112[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
