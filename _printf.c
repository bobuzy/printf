#include "main.h"

/**
 * _printf - Print formatted strings into standard output
 * @format: The string to be printed out
 *
 * Return: The lenght of the output text
 */

int _printf(const char *format, ...)
{
	int i = 0, outputlength = 0;

	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}

	while (format[i])
	{
		if (format[i] != '%')
		{
			outputlength += printchar(format[i]);
		}
		else
		{
			if (format[i + 1] == '%')
			{
				outputlength += printchar('%');
			}
			else if (format[i + 1] == 'c')
			{
				outputlength += printchar(va_arg(args, int));
			}
			else if (format[i + 1] == 's')
			{
				outputlength += printstr(va_arg(args, char*));
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				outputlength += printdig(va_arg(args, int));
			}
			i++;
		}
		i++;
	}
	va_end(args);
	return (outputlength);
}

/**
 * printchar - Print a character into standard output
 * @c: The character to be printed
 *
 * Return: 1, if successful
 */

int printchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * printstr - Print a string into standard output
 * @str: The string to be printed
 *
 * Return: The length of the string
 */

int printstr(char *str)
{
	int outputlength = 0;

	for (; *str != '\0'; str++)
	{
		printchar(*str);
		outputlength += 1;
	}
	return (outputlength);
}


/**
 * printdig - Print a digit recursively
 * @num: The number to be printed
 *
 * Return: The length of the digit printed
 */

int printdig(int num)
{
	unsigned int i;
	int outputlength = 0;

	i = num;

	if (num < 0)
	{
		printchar('-');
		i = -num;
	}

	if (i / 10 != 0)
	{
		printdig(i / 10);
	}

	printchar((i % 10) + '0');
	outputlength += 1;

	return (outputlength);
}
