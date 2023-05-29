#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a single character
 * @types: List of the arguments
 * @buffer: Buffer array to print
 * @flags:  Calculation of the flags
 * @width: Width
 * @precision: specification of precision
 * @size: Size specifiers
 * Return: Number of the characters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char f = va_arg(types, int);

	return (handle_write_char(f, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string of charachters
 * @types: List of the arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: get the width.
 * @precision: Precision of specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, h;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
	str = "(null)";
	if (precision >= 6)
	str = "      ";
	}

	while (str[length] != '\0')
	length++;

	if (precision >= 0 && precision < length)
	length = precision;

	if (width > length)
	{
	if (flags & F_MINUS)
	{
	write(1, &str[0], length);
	for (h = width - length; h > 0; h--)
	write(1, " ", 1);
	return (width);
	}
	else
	{
	for (h = width - length; h > 0; h--)
	write(1, " ", 1);
	write(1, &str[0], length);
	return (width);
	}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percentage sign
 * @types: List of arguments
 * @buffer: Buffer array to handle the print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print integer
 * @types: List of arguments
 * @buffer: Buffer array to handle prints
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convert_size_number(m, size);

	if (m == 0)
	buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
	num = (unsigned long int)((-1) * m);
	is_negative = 1;
	}

	while (num > 0)
	{
	buffer[x--] = (num % 10) + '0';
	num /= 10;
	}

	x++;

	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a, d, i, sum;
	unsigned int z[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	d = 2147483648; /* (2 ^ 31) */
	z[0] = a / d;
	for (i = 1; i < 32; i++)
	{
	d /= 2;
	z[i] = (a / d) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
	sum += z[i];
	if (sum || i == 31)
	{
	char f = '0' + z[i];

	write(1, &f, 1);
	count++;
	}
	}
	return (count);
}
