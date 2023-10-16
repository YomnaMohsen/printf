#ifndef MAIN_H
#define MAIN_H
#define < stdarg.h >

/* strctures */
/**
*struct buffer - struct that defines buffer
*@s: pointer to string
*@len: length of string stored in buffer
*/
typedef struct buffer
{
	char *s;
	int len;
} buf_t;

typedef struct spec
{	
	char s;
	void (*f)(char, va_list);
} spec_t;
/*functions*/
int _printf(const char *format, ...);
buf_t *initbuffer();

#endif
