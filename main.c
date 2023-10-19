#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("%d%d\n", len, len2);
     _printf("Character:[%c]\n", 'H');
	 printf("Character:[%c]\n", 'H');
    _printf("String:yomna[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
     len = _printf("Percent:[%%][%c]\n");
    len2 = printf("Percent:[%%][%c]\n");
	printf("%d%d\n", len, len2);   
	_printf("Unknown:[%r]\n");
    	printf("Unknown:[%r]\n");
	return (0);
}
