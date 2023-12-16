#include "main.h"

/**
 * get_rot13 - prints the rot13'ed string
 * @ap: list of args
 * @buf: pointer to struct
 * Return: int
 */

int get_rot13(va_list ap, buf_t *buf)
{
	int i = 0, j, count = 0;
	char *a;
	char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alpha1[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKL";

	a = va_arg(ap, char *);
	while (a[i] != '\0')
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (a[i] == alpha[j])
			{
				count += cpy_buf(buf, &alpha1[j], 1);
				break;
			}
		}
		if (a[i] != alpha[j])
			count += cpy_buf(buf, &a[i], 1);
		i++;
	}
	return (count);
}

/**
 * rev_string - reverse array of charcters (string)
 * @ap: laist of args
 * @buf: pointer to struct
 * Return: int
 */

int  rev_string(va_list ap, buf_t *buf)
{
	int count = 0, len = 0, i = 0;
	char *s;

	s = va_arg(ap, char *);
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	len--;
	while (len >= 0)
	{
		count += cpy_buf(buf, &s[len], 1);
		len--;
	}
	return (count);
}

