#include "shakeup.h"
/**
 * correctAbsPath - process command if correct info was entered by user
 * @token: raw user input
 * Return: Always 0.
 */
size_t correctAbsPath(char *token)
{
	struct stat st;

	if (stat(token, &st) == 0)
		return (1);
	return (0);
}
