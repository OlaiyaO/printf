#include <unistd.h>

/**
 * _putchar - Custom putchar function
 * @c: Character to print
 *
 * Return: 1 (success) or -1 (failure)
 */

int _putchar(char c)
{
	return write(1, &c, 1);
}
