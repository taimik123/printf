#include "main.h"

/**
 * is_printable - Determines if a character is printable
 * @c1: the char to be evaluated.
 *
 * Return: 1 if char is printable, 0 otherwise
 */
int is_printable(char c1)
{
	if (c1 >= 32 && c1 < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of characters
 * @k: Index at which to start appending
 * @ascii_code1: the ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code1, char buffer[], int k)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexa format code is always 2 digits long */
	if (ascii_code1 < 0)
		ascii_code1 *= -1;

	buffer[k++] = '\\';
	buffer[k++] = 'x';

	buffer[k++] = map_to[ascii_code1 / 16];
	buffer[k] = map_to[ascii_code1 % 16];

	return (3);
}

/**
 * is_digit -this code Verifies if a char is a digit
 * @c1: Character to be evaluated
 *
 * Return: 1 if c1 is a digit, 0 otherwise
 */
int is_digit(char c1)
{
	if (c1 >= '0' && c1 <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - this codeCasts a number to the specified size
 * @num1: num to be casted
 * @size: Number indicating thetype to be casted.
 *
 * Return: Casted value of number
 */
long int convert_size_number(long int num1, int size)
{
	if (size == S_LONG)
		return (num1);
	else if (size == S_SHORT)
		return ((short)num1);

	return ((int)num1);
}

/**
 * convert_size_unsgnd - Casts a num to  specified size
 * @num1: Number to be casted
 * @size: Num indicating type to be casted
 *
 * Return: Casted value of number.
 */
long int convert_size_unsgnd(unsigned long int num1, int size)
{
	if (size == S_LONG)
		return (num1);
	else if (size == S_SHORT)
		return ((unsigned short)num1);

	return ((unsigned int)num1);
}
