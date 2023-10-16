#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

# define NULL_STRING "(null"

/* strctures */
/**
*struct buffer - struct that defines buffer
*@s: pointer to string
*@len: length of string stored in buffer
*/
typedef struct buffer
{
	char *buf;
	char *start;
	int len;
} buf_t;

/**
*struct spec - struct that defines buffer
*@s: char
*@f: pointer to function
*/
typedef struct spec
{
	char s;
	int (*f)(buf_t *, va_list);
} spec_t;
/*functions*/
int _printf(const char *format, ...);
buf_t *initbuffer();
int frmt_specifier(buf_t *buf, const char *format, va_list ap);
int print_s(buf_t *buf, va_list ap);
int print_c(buf_t *buf,  va_list ap);
int print_perc(buf_t *buf,  va_list ap);
void printbuff_free(buf_t *buf, va_list args);


#endif
