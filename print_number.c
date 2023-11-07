#include <stdio.h>
#include "main.h"
#include <stddef.h>


/**
 * print_int - print int
 *
 * @ap: list of  args
 * @buf: pointer to struct
 * Return: int
 */

int print_int(va_list ap, buf_t *buf)
{
	 int pow_r = 1, digit, n;
	 int count = 0;
	 char int_p = '-';

	digit = va_arg(ap, int);

	if (digit < 0)
	{
		count += cpy_buf(buf, &int_p, 1);
		digit = -digit;
	}
	n = digit;
	while (digit > 9)
	{
		digit = digit / 10;
		pow_r *= 10;
	}
	while (pow_r > 0)
	{
		digit = n / pow_r;
		int_p = (digit % 10 + '0');
		count += cpy_buf(buf, &int_p, 1);
		n -= digit * pow_r;
		pow_r /= 10;
	}
	return (count);
}

