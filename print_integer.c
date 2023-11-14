#include "main.h"

/**
 * print_integer - Prints an integer.
 * @args: The va_list of arguments.
 *
 * Return: Number of characters printed.
 */

int print_integer(va_list args)
{
	int input_num = va_arg(args, int);
	int temp_num, last_digit = input_num % 10, current_digit, exp = 1;
	int char_count = 1;

	input_num = input_num / 10;
	temp_num = input_num;

	if (last_digit < 0)
	{
		_putchar('-');
		temp_num = -temp_num;
		input_num = -input_num;
		last_digit = -last_digit;
		char_count++;
	}

	if (temp_num > 0)
	{
		while (temp_num / 10 != 0)
		{
			exp = exp * 10;
			temp_num = temp_num / 10;
		}

		temp_num = input_num;

		while (exp > 0)
		{
			current_digit = temp_num / exp;
			_putchar(current_digit + '0');
			temp_num = temp_num - (current_digit * exp);
			exp = exp / 10;
			char_count++;
		}
	}
	_putchar(last_digit + '0');
	return (char_count);
}
