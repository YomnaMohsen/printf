#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/* strctures */
/**
*struct buffer - struct that defines buffer
*@buf: pointer to string
*@start : pointer to string
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
	unsigned char s;
	int (*f)(va_list, buf_t *,
		unsigned char, int, int, unsigned char)
;
} spec_t;
/*functions*/
int _printf(const char *format, ...);
buf_t *initbuffer();
int print_s(va_list ap, buf_t *buf, unsigned char flag,
	int width, int prec, unsigned char len);
int print_c(va_list ap, buf_t *buf, unsigned char flag,
        int width, int prec, unsigned char len);
int print_perc(va_list ap, buf_t *buf, unsigned char flag,
        int width, int prec, unsigned char len);
void printbuff_free(buf_t *buf, va_list args);
int run_handlers(const char *format, va_list arg, buf_t *buf);
int cpy_buf(buf_t *buf, const char *s, int n);
int (*frmt_specifier (const char *f))(va_list, buf_t *,
	unsigned char, int, int, unsigned char);
#endif
