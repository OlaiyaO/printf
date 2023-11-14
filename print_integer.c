#include "main.h"

/**
 * print_integer - Print an integer value.
 * @args: va_list containing the argument.
 *
 * Return: Number of characters printed.
 */

int print_integer(va_list args)
{
	int value = va_arg(args, int);
	int count = 0;

	if (value == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	count += print_positive_integer(value);

	return (count);
}

/**
 * print_positive_integer - Print the positive part of an integer value.
 * @value: The positive integer value to print.
 *
 * Return: Number of characters printed.
 */

int print_positive_integer(int value)
{
	int count = 0;
	int divisor = 1;

	while (value / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		char digit = '0' + value / divisor;

		write(1, &digit, 1);
		count++;
		value %= divisor;
		divisor /= 10;
	}

	return (count);
}
