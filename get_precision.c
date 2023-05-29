#include "main.h"

/**
 * get_precision -the code for Calculateing the precision for printing
 * @format: code for Formatted string in which to print the arguments
 * @k: this is a List of arguments to be printed.
 * @list1: code forlist of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *k, va_list list1)
{
	int curr_k = ki + 1;
	int precision = -1;

	if (format[curr_k] != '.')
		return (precision);

	precision = 0;

	for (curr_k += 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_digit(format[curr_k]))
		{
			precision *= 10;
			precision += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			precision = va_arg(list1, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (precision);
}
