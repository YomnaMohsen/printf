#include <stdio.h>
#include "main.h"
#include <stddef.h>

/**
 * convert_ub - convert unsigned int to cetrain base
 *
 * @n: unsigned int
 * @base: unsigned int base
 * @buf: pointer to struct
 * Return: int
 */

int convert_ub(unsigned int n, unsigned int base, buf_t *buf)
{
	int count = 0;
	char digit;

	if (n < base)
	{
		digit = n + '0';
		count += cpy_buf(buf, &digit, 1);
	}
	else
	{
		count += convert_ub(n / base, base, buf);
		digit = (n % base) + '0';
		count += cpy_buf(buf, &digit, 1);
	}
	return (count);
}

/**
 * convert_b - convert unsigned int to binary
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
	count += convert_ub(n, 2, buf);
	return (count);
}

/**
 * convert_u - convert unsigned int to decimal then stores it in char buffer
 *
 * @ap: list of  args
 * @buf: pointer to struct
 * Return: int
 */

int convert_u(va_list ap, buf_t *buf)
{
	 unsigned int n;
	 int count = 0;

	n = va_arg(ap, unsigned int);
	count += convert_ub(n, 10, buf);
	return (count);
}

/**
 * convert_o - convert unsigned int number to octal then stores it in char buffer
 *
 * @ap: list of  args
 * @buf: pointer to struct
 * Return: int
 */

int convert_o(va_list ap, buf_t *buf)
{
	 unsigned int n;
	 int count = 0;

	n = va_arg(ap, unsigned int);
	count += convert_ub(n, 8, buf);
	return (count);
}

