#include "shakeup.h"

int nonInteractiveShell(char *buffer, general_t *genHead)
{
	char **bufferTokens;

	bufferTokens = parseBuffer(buffer, genHead);
	if (correctAbsPath(bufferTokens[0]))
		createFork(bufferTokens);
	else
	{
		bufferTokens[0] = findCmd(bufferTokens[0], genHead);
		createFork(bufferTokens);
	}
	return (0);
}
