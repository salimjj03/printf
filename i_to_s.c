#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * wr - ...
 * @w:..
 * Return: ...
 */

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
