#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct p - ..
 * @opt: ..
 * @fmt: ..
 * @ptr: ..
 */

typedef struct p
{
	char opt;
	char fmt;
	int (*ptr)(va_list);
} t_print;

int _printf(const char *format, ...);

#endif
