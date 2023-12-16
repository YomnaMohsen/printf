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
	 unsigned int pow_r = 1;
	 unsigned int n, m;
	 int count = 0, digit;
	 char int_p = '-';

	digit = va_arg(ap, int);

	if (digit < 0)
	{
		count += cpy_buf(buf, &int_p, 1);
		digit = -digit;
	/*	n = -n;*/
	}
	n = digit;
	m = n;
	while (n > 9)
	{
		n = n / 10;
		pow_r *= 10;
	}
	while (pow_r > 0)
	{
		n = m / pow_r;
		int_p = (n % 10 + '0');
		count += cpy_buf(buf, &int_p, 1);
		m -= n * pow_r;
		pow_r /= 10;
	}
	return (count);
}

