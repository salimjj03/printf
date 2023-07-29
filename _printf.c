#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _strlen - find the length of a string
 * @s: string to be count
 * Return: return l
 */

int _strlen(char *s)
{
	 int l = 0;

	for ( ; *s != '\0'; s++)
	{
		l += 1;
	}
	return (l);
}

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
int wr(int w);
int _int(va_list argc)
{
	int w;

	w = va_arg(argc, int);
	wr(w);
	return (0);
}	

int wr(int w)
{
	char x, opt = '-';

	if (w == 0)
	{
		return (0);
	}
	if (w < 0)
	{
		x = ((w * -1) % 10) + '0';
		wr(w / 10);
		if (w > -10)
		{
		write(1, &opt, 1);
		}
		write(1, &x, 1);
		return (0);
		 
	}
	x = (w % 10) + '0';
       	wr(w / 10);
	write(1, &x, 1);
	return (0);
}

/**
 * _char - ...
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

/**
 * _printf - ...
 * @format:..
 * Return: ...
 */

int _printf(const char *format, ...)
{
	va_list argc;
	int j, k;
	t_print p_func[] = {
		{'%', 'c', _char},
		{'%', 's', _string},
		{'%', 'd', _int},
		{'%', 'i', _i}
	};

	va_start(argc, format);
	for (j = 0; format[j] != '\0'; j++)
	{
	for (k = 0; k < 4; k++)
	{
	if ((format[j] == p_func[k].opt) && (format[j + 1] == p_func[k].fmt))
	{
		p_func[k].ptr(argc);
		j++;
	}
	else if (format[j] == '%' && format[j + 1] != 'c' &&
			format[j + 1] != 's' && k == 0 && format[j + 1] != 'd' && format[j + 1] != 'i')
	{
		write(1, &format[j], 1);
	}
	else if (k == 0 && format[j] != '%')
	{
		write(1, &format[j], 1);
	}
	}
	}
		va_end(argc);
		return (j - 1);
}
