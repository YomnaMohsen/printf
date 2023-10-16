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
/*  (void) int len;*/
    int len2;
   

     _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("len in printf%d\n", len2);
/*	printf("len in _printf%d\n", len);*/
	  printf("Character:[%c]\n", 'H');
	  _printf("Character:[%c]\n", 'H');
   _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
/*     len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");*/
/*	printf("%d in org", len);*/
	return (0);
}
