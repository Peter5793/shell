#include "shakeup.h"

/**
 * _strcat - Concatenate two strings
 *
 * @dest: The string to concat to
 * @source: The string to add from
 *
 * Return: Pointer to dest string
 *
 */

char *_strcat(char *dest, char *source)
{
	unsigned int i;

	if ((dest == NULL) || (source == NULL))
		return (dest);
	for (i = 0; i < _strlen(source); i++)
		dest[_strlen(dest) + i] = source[i];
	dest[_strlen(dest) + i] = '\0';
	return (dest);
}
