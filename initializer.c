#include "main.h"
#include <stdlib.h>

/**
* initbuffer -  initialize struct buff
* Return : pointer to struct
*/
buf_t *initbuffer()
{
	buf_t *t;

	t = malloc(sizeof(buf_t));
	if (t == NULL)
		return (NULL);
	t->buf = malloc(sizeof(char) * 1024);
	if (t->buf == NULL)
	{
		free(t);
		return (NULL);
	}
	t->start = t->buf;
	t->len = 0;
	return (t);

}
