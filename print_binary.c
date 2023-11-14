#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary.
 * @args: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */

int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int binary[CHAR_BIT * sizeof(unsigned int)];
	int i, char_count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; num > 0; i++)
	{
		binary[i] = num % 2;
		num = num / 2;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		char_count++;
	}

	return (char_count);
}
