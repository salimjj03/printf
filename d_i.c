#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _int - ...
 * @argc:..
 * Return: ...
 */

int _int(va_list argc)
{
	int w;

	w = va_arg(argc, int);
	wr(w);
	return (0);
}

/**
 * _i - ...
 * @argc:..
 * Return: ...
 */

int _i(va_list argc)
{
	int i;

	i = va_arg(argc, int);
	wr(i);
	return (0);
}
