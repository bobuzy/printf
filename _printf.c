#include "main.h"

/**
 * _printf - Print formatted strings into standard output
 * @format: The string to be printed out
 *
 * Return: The lenght of the output text
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int output = 0;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}
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
			output += write(1, &format[i], 1);
		}
		else
		{
			get_spec f = {0};

			f.f = check_fmt_spec(format[i + 1]);

			if (f.f != NULL)
			{
				output += f.f(args);
			}
			i++;
		}
		i++;
	}
	return (output);
}
