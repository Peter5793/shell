#include "shakeup.h"

size_t correctAbsPath(char *token)
{
	struct stat st;

	if (stat(token, &st) == 0)
		return (1);
	return (0);
}
