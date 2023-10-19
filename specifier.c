#include "main.h"


/**
*frmt_specifier - matches conversion specifier with specifier
*                  conversion fn
*
*@spec: pointer to conversion specifier
*
*Return: if function found return pointer to it
*          otherwise null
*/

int (*frmt_specifier(const char *spec))(va_list, buf_t *,
	unsigned char, int, int, unsigned char)
{
	int j;

	spec_t spec_arr[] = {
		{'s', print_s},
		{'c', print_c},
		{'%', print_perc},
		{0, NULL}
	};
	for (j = 0; spec_arr[j].f; j++)
	{
		if (spec_arr[j].s == *spec)
		{
			return (spec_arr[j].f);
		}
	}
	return (NULL);
}
