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

int (*frmt_specifier(const char *spec))(va_list, buf_t *)
{
	int j;

	spec_t spec_arr[] = {
		{'s', print_s},
		{'c', print_c},
		{'%', print_perc},
		{'d', print_int},
		{'i', print_int},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_h},
		{'X', convert_H},
		{'R', get_rot},
		{'r', rev_string},
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
