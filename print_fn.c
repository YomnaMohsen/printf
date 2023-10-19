#include "main.h"
#include <stdio.h>

/**
*print_s - print string
*@buf: pointer to struct
*@flag: flag modifier
*@width: width modifier
*@prec: precision modifier
*@ap: list of args
*@len: length modifier
*Return: int
*/

int print_s(va_list ap, buf_t *buf, unsigned char flag,
	int width, int prec, unsigned char len)
{
	int count = 0;
	char *s1, *nil = "(null)";

	(void)flag;
	(void)width;
	(void)prec;
	(void)len;


	s1 = va_arg(ap, char *);
	if (!*s1)
		count += cpy_buf(buf, nil, 6);
	while (*s1)
	{
		count += cpy_buf(buf, s1, 1);
		s1++;
	}
	return (count);
}
/**
*print_c - print char
*@buf: pointer to struct
*@flag: flag modifier
*@width: width modifier
*@prec: precision modifier
*@ap: list of args
*@len: length modifier
*Return: int
*/

int print_c(va_list ap, buf_t *buf,unsigned char flag,
	int width, int prec, unsigned char len)
{
	char s1;
	unsigned int count = 0;

	(void)flag;
	(void)width;
	(void)prec;
	(void)len;
	s1 = va_arg(ap, int);
	count += cpy_buf(buf, &s1, 1);
	return (count);
}

/**
*print_perc - print char
*@buf: pointer to struct
*@flag: flag modifier
*@width: width modifier
*@prec: precision modifier
*@len: lengh modifier
*@ap: list of args
*Return: int
*/

int print_perc(va_list ap, buf_t *buf, unsigned char flag,
	int width, int prec, unsigned char len)
{
	char s1 = '%';
	unsigned int count = 0;

	(void)flag;
	(void)width;
	(void)prec;
	(void)len;
	(void)ap;

	count += cpy_buf(buf, &s1, 1);

	return (count);
}

