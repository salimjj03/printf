#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
			format[j + 1] != 's' && k == 0 && format[j + 1] != 'd' &&
			format[j + 1] != 'i')
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
		return (j);
}
