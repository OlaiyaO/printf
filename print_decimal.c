#include "main.h"

/**
 * print_decimal - Prints a decimal (int) number.
 * @args: A va_list containing the argument to print.
 *
 * Return: The number of characters printed.
 */

int print_decimal(va_list args)
{
	int num = va_arg(args, int);
	int count = 0, i;
	char *buffer;

	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}

	if (num == 0)
	{
		count += write(1, "0", 1);
	}
	else
	{
		int num_digits = 0;
		int temp = num;

		while (temp > 0)
		{
			temp /= 10;
			num_digits++;
		}

		buffer = malloc(num_digits);
		if (buffer == NULL)
			return (-1);

		for (i = num_digits - 1; i >= 0; i--)
		{
			buffer[i] = num % 10 + '0';
			num /= 10;
		}

		count += write(1, buffer, num_digits);
		free(buffer);
	}
	return (count);
}
