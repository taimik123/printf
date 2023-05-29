#include "main.h"

/**
 * get_width -this code  get_width - Calculates the width for printing
 * @format: A formatted string used for printing the arguments.
 * @k: a code fora list of arguments that are to be printed
 * @list1:a code for a list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *k, va_list list1)
{
	int curr_k;
	int width = 0;

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_digit(format[curr_k]))
		{
			width *= 10;
			width += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			width = va_arg(list1, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (width);
}
