#include "main.h"

/**
*print_s - print string
*@buf: pointer to struct
*@ap: list of args
*@i: int
*Return: int
*/

int print_s(buf_t *buf, int i, va_list ap)
{
	int count = 0;
	char *s;

	s = va_arg(ap, char *);
	while (*s)
	{
		buf->s[i] = va_arg(ap, char *);
		i++;
		count++;
	}
	return (count);
}
/**
*print_ - print char
*@buf: pointer to struct
*@ap: list of args
*@i: int
*Return: int
*/

int print_c(buf_t *buf, int i, va_list ap)
{
	int count = 0;
	char s;

	s = va_arg(ap, int);
	buf->s[i] = s;
	count++;
	return (count);
}

