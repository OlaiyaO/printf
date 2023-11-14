#include "main.h"

/**
 * print_number - Prints a number with a given base.
 * @n: The number to print.
 * @base: The base of the number.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int print_number(unsigned int n, int base)
{
	int count = 0;

	if (n / base)
		count += print_number(n / base, base);

	count += _putchar((n % base) + '0');

	return (count);
}

/**
 * print_number_hex - Prints a number in hexadecimal format.
 * @n: The number to print.
 * @uppercase: If 1, print in uppercase; if 0, print in lowercase.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int print_number_hex(unsigned int n, int uppercase)
{
	int count = 0;

	if (n / 16)
		count += print_number_hex(n / 16, uppercase);

	if (n % 16 < 10)
		count += _putchar((n % 16) + '0');
	else
	{
		if (uppercase)
			count += _putchar((n % 16) - 10 + 'A');
		else
			count += _putchar((n % 16) - 10 + 'a');
	}

	return (count);
}

