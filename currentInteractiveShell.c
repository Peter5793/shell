#include "shakeup.h"

int interactiveShell()
{
	char **bufferTokens, *buffer = NULL;
	size_t len;

	while (1)
	{
		printPrompt("shakeup$ ");
		buffer = getUserInput(buffer, &len);
		bufferTokens = parseBuffer(buffer);
		if (correctAbsPath(bufferTokens[0]))
			createFork(bufferTokens);
		else
		{
			bufferTokens[0] = findCmd(bufferTokens[0]);
			createFork(bufferTokens);
		}
	}
	return (0);
}
