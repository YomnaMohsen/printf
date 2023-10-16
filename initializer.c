#include "main.h"
#include <stdlib.h>

/**
* _cpy - copy n bytes into main buffer 
* @buf: pointer to struct
* @src: pointer to src that will be copied
* n: number of bytes to be copied
* Return: no of bytes copied
*/

/**int *cpy(buf_t *buf, const char *src, int n)
{
	int index = 0;
	
	while (index < n)
	{
		*(buf->buf) = *(src + index);
		index++;
		buf->len++;
	}

	t->start = t->buf;
	t->len = 0;
	return (t);

}*/
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
	t->buf = malloc(sizeof(char) * 1024);
	if (t->buf == NULL)
	{
		free(t);
		return (NULL);
	}
/*	t->start = t->buf;*/
	t->len = 0;
	return (t);

}
