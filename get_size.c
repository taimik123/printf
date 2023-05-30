#include "main.h"

/**
 * get_size - this code calculates size to cast argument
 * @format: code for formatted string inwhich to print arguments
 * @k: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *k)
{
	int curr_k = *k + 1;
	int size = 0;

	if (format[curr_k] == 'l')
		size = S_LONG;
	else if (format[curr_k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*k = curr_k - 1;
	else
		*k = curr_k;

	return (size);
}
