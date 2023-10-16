#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void printbuff_free(buf_t *buf, va_list args);

/**
* printbuff_free - print buffer then free it
* @buf: pointer to struct
* @args: list of args
* Return: Nothing
*/

void printbuff_free(buf_t *buf, va_list args)
{
	va_end(args);
	write(1, buf->start, buf->len);
	free(buf->start);
	free(buf);
}
/**
* _printf - produces output accroding to format
* @format: string format
* Return:  int
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int count;
	buf_t *buf;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	buf = initbuffer();
	if (buf == NULL)
		return (-1);
	va_start(ap, format);
	buf->start = buf->buf;
	count = frmt_specifier(buf, format, ap);
	
	buf->len = (count + 1);
	buf->buf[count] = '\0';
	/*printf("%d", buf->s[11]);*/
	printbuff_free(buf, ap);
	return (count);
}
