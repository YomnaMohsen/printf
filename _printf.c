#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int run_handlers(const char *format, va_list args, buf_t *buf);
void printbuff_free(buf_t *buf, va_list args);
int _printf(const char *format, ...);
/**
* run_handlers - process string read from _printf
* @buf: pointer to struct
* @args: list of args
* @format: string format
* Return: int
*/

int run_handlers(const char *format, va_list args, buf_t *buf)
{
	int i, count = 0;
	int (*f)(va_list, buf_t *);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			
			f = frmt_specifier(format + i + 1);
			if  (f !=  NULL)
			{
				i++;
				count += f(args, buf);
				continue;
			}
			else if (*(format + i + 1) == '\0')
			{
				count = -1;
				break;
			}
		}
		count += cpy_buf(buf, (format + i), 1);
	}
	return (count);
}

/**
* printbuff_free -  free buf
* @buf: pointer to struct
* @args: list of args
* Return: Nothing
*/

void printbuff_free(buf_t *buf, va_list args)
{
	write(1, buf->start, buf->len);
	va_end(args);
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

	if (format == NULL)
		return (-1);
	buf = initbuffer();
	if (buf == NULL)
		return (-1);
	va_start(ap, format);
	count = run_handlers(format, ap, buf);
	printbuff_free(buf, ap);
	return (count);
}
