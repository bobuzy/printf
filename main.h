#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/**
 * struct fmt - Struct name
 * @abc: List of format specifiers
 * @f: The function associated
 */

typedef struct fmt
{
	char abc;
	int (*f)(va_list);
} get_spec;

int _printf(const char *format, ...);
int (*check_fmt_spec(char s))(va_list);
int printchar(va_list);
int printstring(va_list);
int printpercent(va_list args);
int printdigit(va_list args);
int printdig(int n);

#endif
