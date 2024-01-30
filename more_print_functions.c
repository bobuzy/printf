#include "main.h"

/**
 * printunsigned - Print an unsigned integer in base 10.
 * @args: A va_list of arguments
 *
 * Return: The number of characters printed.
 */

int printunsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int divisor = 1;
	int digits = 0;

	while (num / divisor > 9)
	{
		divisor *= 10;
		digits++;
	}

	while (divisor > 0)
	{
		char digit = (num / divisor) % 10 + '0';

		write(1, &digit, 1);
		divisor /= 10;
	}
	return (digits + 1);
}


/**
 * printoctal - Print an unsigned integer in octal format.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters printed.
 */

int printoctal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int i, length = 0;

	do {
		buffer[length++] = (num % 8) + '0';
		num /= 8;
	} while (num != 0);

	for (i = length - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (length);
}

/**
 * printhex - Print an unsigned integer in hexadecimal format.
 * @args: A va_list of arguments.
 * @uppercase: A flag indicating whether to print uppercase
 * or lowercase letters.
 *
 * Return: The number of characters printed.
 */

int printhex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int i, length = 0;

	do {
		int digit = num % 16;

		buffer[length++] = digit < 10 ? digit + '0' : (digit - 10) +
			(uppercase ? 'A' : 'a');
		num /= 16;
	} while (num != 0);

	for (i = length - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (length);
}

/**
 * printhex_upper - Print an unsigned integer in uppercase hexadecimal format.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters printed.
 */

int printhex_upper(va_list args)
{
	return (printhex(args, 1));
}

/**
 * printhex_lower - Print an unsigned integer in lowercase hexadecimal format.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters printed.
 */

int printhex_lower(va_list args)
{
	return (printhex(args, 0));
}
