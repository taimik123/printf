#include "main.h"
/**
 * handle_print -kode to Print an argument based on  type
 * @fmt: code for Formttd str to print args.
 * @list1:this is jst  List1 of arguments to be printed.
 * @index: index is defined.
 * @buffer:code for Buffer array to handle print.
 * @flags: this code Calculates active flags
 * @width: code to get width.
 * @precision: code for Precision specification
 * @size: Size specifier code
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *index, va_list list1, char buffer[],
	int flags, int width, int precision, int size)
{
	int k, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (k = 0; fmt_types[k].fmt != '\0'; k++)
		if (fmt[*index] == fmt_types[k].fmt)
			return (fmt_types[k].fn(list1, buffer, flags, width, precision, size));

	if (fmt_types[k].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &fmt[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
