#include "main.h"
#include <stdio.h>

void print_null(buf_t *buf);
/**
*@print_null - print null
*@buf : pointer to struct
*@Return : Nothing
*/

void print_null(buf_t *buf)
{
	char *s = "(null)";
	while (*s)
	{
		*(buf->buf) = *s;
		s++;
		(buf->buf)++;
	}
		
	
}
/**
*print_s - print string
*@buf: pointer to struct
*@ap: list of args
*Return: int
*/

int print_s(buf_t *buf, va_list ap)
{
	int count = 0;
	char *s1;

	s1 = va_arg(ap, char *);
	if (!*s1)
		print_null(buf);
	while (*s1)
	{
		*(buf->buf) = *s1;
		(buf->buf)++;
		s1++;
		count++;
	}
	return (count);
}
/**
*print_c - print char
*@buf: pointer to struct
*@ap: list of args
*Return: int
*/

int print_c(buf_t *buf, va_list ap)
{
	int count = 0;
	char s1;

	s1 = va_arg(ap, int);
	*(buf->buf) = s1;
	(buf->buf)++;
	count++;
	return (count);
}

/**
*print_perc - print char
*@buf: pointer to struct
*@ap: list of args
*Return: int
*/

int print_perc(buf_t *buf, va_list ap)
{
	int count = 0;
	char s1;

	s1 = va_arg(ap, int);
	*(buf->buf) = s1;
	(buf->buf)++;
	count++;
	return (count);
}

