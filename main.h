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
int _strlen(char *s);
int _char(va_list argc);
int _string(va_list argc);
int _int(va_list argc);
int wr(int w);
int _i(va_list argc);

#endif
