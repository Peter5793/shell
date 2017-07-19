#include "shakeup.h"

/**
 * __strcat - Concatenate two strings
 * @dest: The string to concat to
 * @src: The string to add from
 * Return: Pointer to dest string
 */
char *__strcat(char *dest, char *src)
{
	int len = 0;
	int i;

	while (dest[len])
	{
		len++;
	}
	for (i = 0; src[i]; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i + 1] = '\0';
	return (dest);
}
