#include "main.h"

/**
 * printbinary - Print the binary representation of an unsigned integer.
 * @args: A variable argument list containing the unsigned integer to print.
 *
 * Return: The number of characters printed.
 */

int printbinary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[33];
	int length = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num)
	{
		binary[length++] = (num % 2) + '0';
		num = num / 2;
	}

	while (length > 0)
	{
		length--;
		write(1, &binary[length], 1);
	}
	return (length);
}
