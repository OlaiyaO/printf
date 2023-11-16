#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct FormatSpecifier - Represents a format specifier and its handler.
 * @specifier: The format specifier character (e.g., 'c', 's', 'd', etc.).
 * @handler: Pointer to the function that handles printing for this specifier.
 *
 * Description:
 * This structure associates a format specifier character
 *	with its corresponding
 * handler function. It is used to organize and
 *	manage different format specifiers
 * in a custom printf-style function.
 */

typedef struct FormatSpecifier
{
	char specifier;
	int (*handler)(va_list);
} FormatSpecifier;

int _printf(const char *format, ...);

int _putchar(char c);

int print_char(va_list args);

int print_str(va_list args);

int print_percent(va_list args);

int print_decimal(va_list args);

int print_integer(va_list args);

int print_positive_integer(int value);

int handle_specifier(char specifier, va_list args);

int parse_format(const char *format, va_list args);

int print_binary(va_list args);

int print_number(unsigned int n, int base);

int print_number_hex(unsigned int n, int uppercase);

int print_unsigned(va_list args);

int print_octal(va_list args);

int print_hex(va_list args);

int print_HEX(va_list args);

int print_string_with_non_printable(va_list args);

int print_pointer(va_list args);
#endif /* MAIN_H */
