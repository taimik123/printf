#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct formating_112 - struct for formating
 *
 * @specifyingformatt112: The format specifier character.
 * @fn: Pointer to the function associated with the format specifier.
 */
struct formating_112
{
	char specifyingformatt112;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct formating_112 fmt_t - Struct operation
 *
 * @formating_112: The format string
 * @fm_t: The format specifier.
 */
typedef struct formating_112 fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *formating_112, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions that are used to print chars and strings */
int print_char112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent112(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions that are used to print numbers */
int print_int112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal112(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper112(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa112(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function that is used to print non printable characters */
int print_non_printable112(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion which is used to print memory address */
int print_pointer112(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions that are used to handle other specifiers */
int get_flags112(const char *format, int *i);
int get_width112(const char *format, int *i, va_list list);
int get_precision112(const char *format, int *i, va_list list);
int get_size112(const char *format, int *i);

/*Function which are used to print string in reverse*/
int print_reverse112(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function that is often used to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char112(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number112(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num112(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer112(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd112(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code112(char, char[], int);
int is_digit(char);

long int convert_size_number112(long int num, int size);
long int convert_size_unsgnd112(unsigned long int num, int size);

#endif /* MAIN_H */

