#include "main.h"

/**
 * check_fmt_spec - Check the format specifer and assign the right function
 * @s: The format specifiers
 *
 * Return: The assigned function pointer
 */

int (*check_fmt_spec(char s))(va_list)
{
	get_spec specs[] = {
	{ 'c', printchar },
	{ 's', printstring },
	{ '%', printpercent },
	{ 'd', printdigit },
	{ 'i', printdigit },
	{ 0, NULL }
	};

	int i = 0;

	while (i < 5)
	{
		if (s == specs[i].abc)
		{
			return (specs[i].f);
		}
		i++;
	}

	return (0);
}
