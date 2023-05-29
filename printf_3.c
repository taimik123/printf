#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ibm = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
	return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
	buffer[ibm--] = map_to[num_addrs % 16];
	num_addrs /= 16;
	length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';
	if (flags & F_PLUS)
	extra_c = '+', length++;
	else if (flags & F_SPACE)
	extra_c = ' ', length++;

	ibm++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ibm, length,
	width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: List a type of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of charachters printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	return (write(1, "(null)", 6));

	while (str[l] != '\0')
	{
	if (is_printable(str[l]))
	buffer[l + offset] = str[l];
	else
	offset += append_hexa_code(str[l], buffer, l + offset);

	l++;
	}

	buffer[l + offset] = '\0';

	return (write(1, buffer, l + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints a reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle the print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Numbers of charchters printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int l, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
	UNUSED(precision);

	str = ")Null(";
	}
	for (l = 0; str[l]; l++)
	;

	for (l = l - 1; l >= 0; l--)
	{
	char y = str[l];

	write(1, &y, 1);
	count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: List a type of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c;
	char *str;
	unsigned int k, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
	for (b = 0; in[b]; b++)
	{
	if (in[b] == str[k])
	{
	c = out[b];
	write(1, &c, 1);
	count++;
	break;
	}
	}
	if (!in[b])
	{
	c = str[k];
	write(1, &c, 1);
	count++;
	}
	}
	return (count);
}
