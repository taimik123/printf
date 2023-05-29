#include "main.h"

/************************* WRITE HANDLE *************************/
/***
 * handle_write_char:for outputting a string.
 * @c:this represents the character type
 * @buffer: this is An array used for storing the printed output
 * @flags:  this Determines the active flags during printing.
 * @width: this Specifies the width of the output.
 * @precision: this code Specifies the precision of the output
 * @size: this code Specifies the size of the output.
 * Return: the total Number of chars printed.
 */
int handle_write_char(char c1, char buffer[],
	int flags, int width, int precision, int size)
{ /* here character is stored on the left and paddind at buffer's right side */
	int k = 0;
	char paddingChar1 = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		paddingChar1 = '0';

	buffer[k++] = c1;
	buffer[k] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			buffer[BUFF_SIZE - k - 2] = paddingChar1;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/*************************to  WRITE NUMBER *************************/
/**
 * write_number -  This function is the one responsible for outputting a string
 * @is_negative: it Indicates whether the number is negative or not.
 * @ind:Represents the character type.
 * @buffer: An array used for storing the printed output.
 * @flags:  Determines the active flags during printing.
 * @width: geting the  width.
 * @precision: precision of output  specifier
 * @size: this code specifies Size output
 *
 * Return:the total  Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char paddingChar1 = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddingChar1 = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, paddingChar1, extra_ch));
}

/**
 * write_num -this is just a function that  Write a number using a bufffer
 * @ind: this is Index at which the number starts on the buffer in a code.
 * @buffer: this is the Buffer itself
 * @flags:this code just indicates the Flags
 * @width:here its where the  width is specified
 * @prec: Precision specifier is determined
 * @length: Number length is specified in the code
 * @extra_c: Extra character is specified in the code
 * @paddingChar1:width of pugging
 * Return: total Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char paddingChar1, char extra_c)
{
	int k, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* code for printf(".0d", 0) here  no character is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = paddingChar1 = ' '; /* width is shown with padding ' ' */
	if (prec > 0 && prec < length)
		paddingChar1 = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (k = 1; k < width - length + 1; k++)
			buffer[k] = paddingChar1;
		buffer[k] = '\0';
		if (flags & F_MINUS && paddingChar1 == ' ')/* xtra chr to buf */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], k - 1));
		}
		else if (!(flags & F_MINUS) && paddingChar1 == ' ')/* chr */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], k - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && paddingChar1 == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd -function responsible for writing an unsigned number.
 * @is_negative:A number indicating if the given number is negative.
 * @ind: The index at which the number starts in the buffer.
 * @buffer:An array of characters used for storing the output.
 * @flags:this code  Flags specifiers
 * @width:this codeis a Width specifier
 * @precision: this is  Precision specifier code
 * @size: Size output is specified
 *
 * Return: total Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position k */
	int length = BUFF_SIZE - ind - 1, k = 0;
	char paddingChar1 = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		paddingChar1 = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddingChar1 = '0';

	if (width > length)
	{
		for (k = 0; k < width - length; k++)
			buffer[k] = paddingChar1;

		buffer[k] = '\0';

		if (flags & F_MINUS) /* xtra char to the left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], k));
		}
		else /* to  Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], k) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer -code function is responsible for writing memory address.
 * @buffer:this is An array of characters used for storing the output.
 * @ind: this code is for Index at which the number starts in the buffer
 * @length:code to determine Length of number
 * @width: Width specifier code
 * @flags: Flags specifier code
 * @paddingChar1:width of pudding
 * @extra_c: Char representing extra character
 * @padd_start: this is the Index at which padding should start
 *
 * Return: total Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char paddingChar1, char extra_c, int padd_start)
{
	int k;

	if (width > length)
	{
		for (k = 3; k < width - length + 3; k++)
			buffer[k] = paddingChar1;
		buffer[k] = '\0';
		if (flags & F_MINUS && paddingChar1 == ' ')/* xtra charto left ofbuffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], k - 3));
		}
		else if (!(flags & F_MINUS) && paddingChar1 == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], k - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && paddingChar1 == '0')/*xtra charto left padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], k - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
