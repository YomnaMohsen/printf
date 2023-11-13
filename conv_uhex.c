#include "main.h"
#include <stddef.h>

/**
 * convert_uh - convert unsigned int to hec value
 *
 * @n: unsigned int
 * @base: unsigned int base
 * @flag: int value to indicate capital or small hex
 * @buf: pointer to struct
 * Return: int
 */

int convert_uh(unsigned int n, unsigned int base, int flag, buf_t *buf)
{
	int count = 0, tmp;
	char digit;

	if (n > base)
	{
		count += convert_uh(n / base, base, flag, buf);
	}
	tmp = n % base;
	if ((tmp) > 9 && flag)
	{
		digit = ((tmp) - 10) + 'A';
	}
	else if ((tmp) > 9 && (!flag))
	{
		digit = ((tmp) - 10) + 'a';
	}
	else
	{
		digit = (tmp) + '0';
	}
	count += cpy_buf(buf, &digit, 1);
	return (count);
}

/**
 * convert_h - convert unsigned int to hexa (abcd)
 *
 * @ap: list of  args
 * @buf: pointer to struct
 * Return: int
 */

int convert_h(va_list ap, buf_t *buf)
{
	 unsigned int n;
	 int count = 0;

	n = va_arg(ap, unsigned int);
	count += convert_uh(n, 16, 0, buf);
	return (count);
}

/**
 * convert_H - convert unsigned int to hexa (ABCD)
 *
 * @ap: list of  args
 * @buf: pointer to struct
 * Return: int
 */

int convert_H(va_list ap, buf_t *buf)
{
	 unsigned int n;
	 int count = 0;

	n = va_arg(ap, unsigned int);
	count += convert_uh(n, 16, 1, buf);
	return (count);
}
