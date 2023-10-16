#include "main.h"
#include <stdio.h>

/**
* frmt_specifier - format specifier arg in printf
*@buf: pointer to struct
*@format: parameter to string
* @ap: list of args
* Return:  int
*/

int frmt_specifier(buf_t *buf, const char *format, va_list ap)
{
	int count = 0, i = 0, j = 0;

	spec_t spec_arr[] = {
		{'s', print_s},
		{'c', print_c},
		{'%', print_perc},
		{'\0', NULL}
	};
	while (format[i])
	{
		if (format[i] != '%')
		{
		/*	printf("in first %d\n",i);*/
			*(buf->buf) = format[i];
			(buf->buf)++;
			count++;
		}
		else
		{
			
			while (spec_arr[j].s)
			{
				if (format[i+1] == spec_arr[j].s)
				{
					count += spec_arr[j].f(buf, ap);
					i++;
					break;
				
				}
				j++;
			}
			
			
			if (spec_arr[j].s == '\0')
			{
			/*	printf ("in if\n"); */
				*(buf->buf) = '%';
				(buf->buf)++;
				count++;
				if (format[i+1])
				{
					(*buf->buf) = format[i+1];
					(buf->buf)++;
					count++;
				}
				else
					break;
			}
		}
		j = 0;
		i++;
	}
/*	printf("%d", count);*/
	return (count);
}
