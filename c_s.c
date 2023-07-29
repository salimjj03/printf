#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _char - ...
 * @argc:..
 * Return: ...
 */

int _char(va_list argc)
{
	char c;

	c = va_arg(argc, int);
	write(1, &c, 1);
	return (0);
}

/**
 * _string - ...
 * @argc:..
 * Return: ...
 */

int _string(va_list argc)
{
	char *p;

	p = va_arg(argc, char*);
	write(1, p, _strlen(p));
	return (0);
}
