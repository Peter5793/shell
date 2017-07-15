#include "shakeup.h"

int nonInteractiveShell(char *buffer)
{
	char **bufferTokens;

	bufferTokens = parseBuffer(buffer);
	if (correctAbsPath(bufferTokens[0]))
		createFork(bufferTokens);
	else
	{
		bufferTokens[0] = findCmd(bufferTokens[0]);
		createFork(bufferTokens);
	}
	return (0);
}
