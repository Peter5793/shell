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
 * @genHead: general struct
 * Return: Pointer to duplicate string
 *
 */
char *_strdup(const char *s, general_t *genHead)
{
	char *result;
	unsigned int i, len;

	if (!s)
		return (NULL);
	len = _strlen(s);
	result = malloc(++len * sizeof(char));
	if (result == NULL)
		return (NULL);
	addMemAddress(genHead, (void *)result);

	for (i = 0; s[i]; i++)
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}

/**
 * _strcmp - compares 2 strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: - 0 if same or integer of (s1[i] - s2[i]) otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
			return (0);
	}
	return (s1[i] - s2[i]);
}
