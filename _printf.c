#include "main.h"

/**
* _printf - produces output accroding to format
* @format: string format
* Return:  int
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;
	buf_t *buf;
	
	if (format == NULL)
		return (-1);
	b = initbuffer();
	if (buf == NULL)
		return (-1);
	frmt_specifier(buf, format, ap);

	
	}
	printf("\n");
	va_end(ap);
}
