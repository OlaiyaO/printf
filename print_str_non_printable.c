#include "main.h"

/**
 * hex_digit - Convert a decimal digit to its hexadecimal representation.
 * @digit: The decimal digit (0-15).
 * Return: The corresponding hexadecimal character.
 */

char hex_digit(int digit)
{
	if (digit >= 0 && digit <= 9)
		return (digit + '0');
	else if (digit >= 10 && digit <= 15)
		return (digit - 10 + 'A');
	else
		return ('\0');
}

/**
 * print_string_with_non_printable - Print
 *	-a string with non-printable characters.
 * @args: The va_list of arguments.
 * Return: The count of characters printed.
 */

int print_string_with_non_printable(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			_putchar('\\');
			count++;
			_putchar('x');
			count++;
			_putchar(hex_digit((*str >> 4) & 0xF));
			count++;
			_putchar(hex_digit(*str & 0xF));
			count++;
		} else
		{
			_putchar(*str);
			count++;
		}
		str++;
	}

	_putchar('\n');
	count++;
	return (count);
}
