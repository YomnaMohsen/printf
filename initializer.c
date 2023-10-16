#include "main.h"
#include <stdlib.h>

/**
* initbuffer - initialize buffer struct
* Return: pointer to struct
*/

buf_t *initbuffer()
{
	buf_t *t;
	
	t = malloc(sizeof(buf_t));
	if (t == NULL)
		return (NULL);
	t->s = malloc(sizeof(char) * 1024);
	if (t->s == NULL)
	{
		free(t);
		return (NULL);
	}
	t->len = 0;
	return (t);

}
