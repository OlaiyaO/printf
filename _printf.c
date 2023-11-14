#include "main.h"

/**
 * _printf - Prints formatted text to stdout.
 * @format: The format string containing format specifiers.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);

	return (count);
}

/**
 * parse_format - Parses and processes the format string.
 * @format: The format string.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int parse_format(const char *format, va_list args)
{
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				count += write(1, "%", 1);
				break;
			}
			count += handle_specifier(*format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	return (count);
}

/**
 * handle_specifier - Handles a specific specifier.
 * @specifier: The specifier character.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed (excluding null byte).
 */

int handle_specifier(char specifier, va_list args)
{
	FormatSpecifier specifiers[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_integer},
		{'\0', NULL}
	};
	int i = 0;

	while (specifiers[i].specifier != '\0')
	{
		if (specifier == specifiers[i].specifier)
			return (specifiers[i].handler(args));
		i++;
	}
	return (write(1, &specifier, 1));
}
