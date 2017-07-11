#include "shakeup.h"

/**
 * _strlen - Computes length of string
 * @str: The string
 *
 * Return: Length
 *
 */

unsigned int _strlen(const char *str)
{
	unsigned int length = 0;

	if (!str)
		return (0);
	for (length = 0; str[length]; length++)
		;
	return (length);
}

/**
 * _strdup - Duplicate a string
 * @s: The string to duplicate
 *
 * Return: Pointer to duplicate string
 *
 */

char *_strdup(const char *s)
{
	char *result;
	unsigned int i, len;

	if (!s)
		return (NULL);
	len = _strlen(s);
	result = malloc(++len * sizeof(char));
	for (i = 0; s[i]; i++)
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}
