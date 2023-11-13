#include <stdio.h>
#include "main.h"
#include <stddef.h>


/**
 * conv_b - convert unsigned int to binary
 *
 * @ap: list of  args
 * @buf: pointer to struct
 * Return: int
 */

int convert_b(va_list ap, buf_t *buf)
{
	 unsigned int n;
	 int count = 0;

	n = va_arg(ap, unsigned int);
	count += convert_ub(n, buf);
	return (count);
}
/**
 * conv_ub - convert unsigned int to binary
 *
 * @n: unsigned int
 * @buf: pointer to struct
 * Return: int
 */

int convert_ub(unsigned int n, buf_t *buf)
{
	int count = 0;
	char digit;

	if (n == 0 || n == 1)
	{
		digit = n + '0';
		count += cpy_buf(buf, &digit , 1);
	}
	else
	{
		count += convert_ub(n / 2, buf);
		digit = (n % 2) + '0';
		count += cpy_buf(buf, &digit , 1);
	}
	return (count);
}
