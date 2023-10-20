#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
*print_s - print string
*@buf: pointer to struct
*@ap: list of args
*Return: int
*/

int print_s(va_list ap, buf_t *buf)
{
	int count = 0;
	char *s1, *nil = "(null)";

	s1 = va_arg(ap, char *);
	if (s1 == NULL)
	{
		count += (cpy_buf(buf, nil, 6));
		return (count);
	}
	while (*s1)
	{
		count += cpy_buf(buf, s1, 1);
		s1++;
	}
	return (count);
}
/**
*print_c - print char
*@ap: list of args
*@buf: pointer to struct
*Return: int
*/

int print_c(va_list ap, buf_t *buf)
{
	char s1;
	int count = 0;

	s1 = va_arg(ap, int);
	count += cpy_buf(buf, &s1, 1);
	return (count);
}

/**
*print_perc - print char
*@buf: pointer to struct
*@ap: list of args
*Return: int
*/

int print_perc(va_list ap, buf_t *buf)
{
	char s1 = '%';
	int count = 0;

	(void)ap;

	count += cpy_buf(buf, &s1, 1);

	return (count);
}
