#include "main.h"

/************************* FOR PRINT CHAR *************************/

/**
 * print_char - this Prints a character
 * @types: List a couple of arguments
 * @buffer: Buffer array to handle print
 * @flags: this one  Calculates active flags
 * @width: this is a Width
 * @precision: this is the Precision specification
 * @size: Size specifier operator
 * Return: Number of characters which are printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char char1 = va_arg(types, int);

	return (handle_write_char(char1, buffer, flags, width, precision, size));
}
/************************* FOR PRINT A STRING *************************/
/**
 * print_string - this code Prints a string
 * @types:this code  List a of arguments
 * @buffer this code : Buffer array to handle print
 * @flags: this code  Calculates active flags
 * @width: this is where to get width.
 * @precision: Precision specification
 * @size: this code is  Size specifier
 * Return: this code returns Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, x;
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
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/*************************  TO PRINT PERCENT SIGN *************************/
/**
 * print_percent - this code Prints a percent sign
 * @types: this code  Lista of arguments
 * @buffer: this code Buffer array to handle print
 * @flags:  this code Calculates active flags
 * @width: this code get width.
 * @precision: this code Precision specification
 * @size: this code Size specifier
 * Return: this code Number of chars printed
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

/************************* to  PRINT INT *************************/
/**
 * print_int - code to Print int
 * @types: code to Lista of arguments
 * @buffer:code  Buffer array to handle print
 * @flags:  code to Calculates active flags
 * @width: code to get width.
 * @precision: code for getting Precision specification
 * @size: code for Size specifier
 * Return: code for Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
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
 * print_binary - this code Prints an unsigned number
 * @types: this code Lista of arguments
 * @buffer: this code Buffer array to handle print
 * @flags:  this code Calculates active flags
 * @width: this code get width.
 * @precision: this code Precision specification
 * @size: this code Size specifier
 * Return: this code Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, x, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (x = 1; x < 32; x++)
	{
		m /= 2;
		a[x] = (n / m) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
			char z = '0' + a[x];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
