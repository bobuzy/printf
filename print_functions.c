#include "main.h"


/**
 * printchar - Print a character
 * @args: The character to be printed
 *
 * Return: 1
 */

int printchar(va_list args)
{
	char c = va_arg(args, int);

	if (args == NULL)
	{
		return (-1);
	}

	if (c < 32 || c > 126)
	{
		return (-1);
	}

	return (write(1, &c, 1));
}



/**
 * printstring - Print a string
 * @args: The string to be printed
 *
 * Return: String length
 */

int printstring(va_list args)
{
	int length = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}

	while (str[length] != '\0')
	{
		length++;
	}

	return (write(1, str, length));
}



/**
 * printdigit - Print a digit
 * @args: The number to be printed
 *
 * Return: The lenght og the digit
 */

int printdigit(va_list args)
{
	int num = va_arg(args, int);

	if (num == INT_MIN)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (num == INT_MAX)
	{
		return (write(1, "2147483647", 10));
	}

	if (num < 0)
	{
		char c = '-';

		write(1, &c, 1);
		num = -num;
	}

	if (num == 0)
	{
		char c = '0';

		return (write(1, &c, 1));
	}
	return (printdig(num));
}


/**
 * printdig - Print a number recursively
 * @n: The number to be printed
 *
 * Return: The digit length
 */

int printdig(int n)
{
	int num_printed;
	char c;

	if (n / 10 == 0)
	{
		c = n + '0';
		return (write(1, &c, 1));
	}

	num_printed = printdig(n / 10);
	c = (n % 10) + '0';

	return (write(1, &c, 1) + num_printed);
}



/**
 * printpercent - Print the percent symbol
 * @args: void
 *
 * Return: 1
 */

int printpercent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
