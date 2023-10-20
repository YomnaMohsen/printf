#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int cpy_buf(buf_t *buf, const char *s, int n);
buf_t *initbuffer(void);
/**
* cpy_buf - copy src memory area to buffer
* @s: char to be copied
* @n: number of charcters
* @buf: pointer to strcture
* Return: number of char copied
*/
int cpy_buf(buf_t *buf, const char *s, int n)
{
	int index = 0;

	while (index < n)
	{
		*(buf->buf) = s[index];
		(buf->len)++;
		index++;
		if (buf->len == 1024)
		{
			write(1, buf->start, buf->len);
			buf->buf = buf->start;
			buf->len = 0;
		}
		else
			(buf->buf)++;

	}
	return (n);
}
/**
* initbuffer - initialize struct buff
* Return: pointer to struct buf_t
*/
buf_t *initbuffer(void)
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
