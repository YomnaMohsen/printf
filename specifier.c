#include "main.h"

/**
* frmt_specifier - format specifier arg in printf
*@buf: pointer to struct
* @ap: list of args
* Return:  int
*/

int frmt_specifier(buf_t *buf, const char *format, va_list ap);
{
	int count = 0, i = 0, j = 0;

	spec_t spec_arr[] = {
		{'s', print_s},
		{'c', print_c},
		{'%', print_perc},
		{'\0', NULL}
	};
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			buf->s[i] = format[i];
			i++;
			count++;
		}
		else 
		{
			while (spec_arr[j].s)
			{
				if (format[i] == spec_arr[j].s)
				{
					spc_arr.f(buf, i, ap);
				}
				j++;
			}

		}
		i++;


	
	}
	printf("\n");
	va_end(ap);
}
