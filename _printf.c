#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;

	va_list ap;

	char *p, *start;

	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);

		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, ap);
		p = get_precison(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to (start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		else 
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end (ap);
	return (sum);
}
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

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			f = frmt_specifier(format + i + 1);
			if (f != NULL)
			{
				i++;
				count += f(args, buf);
				continue;
			}
			else if (format[i + 1] == '\0')
			{
				count = -1;
				break;
			}
		}
		count += cpy_buf(buf, (format + i), 1);
	}
	return (count);
}
