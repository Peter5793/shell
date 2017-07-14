#include "shakeup.h"

int interactiveShell()
{
	char **bufferTokens, *buffer = NULL;
	size_t len = 300;

	while (1)
	{
		printPrompt("shakeup$");
		if (buffer == NULL)
			buffer = mallocBuffer(len);
		getUserInput(&buffer, &len);
		bufferTokens = parseBuffer(buffer);
		if (correctAbsPath(bufferTokens[0]))
			createFork(bufferTokens);
		else
		{
			bufferTokens[0] = findCmd(bufferTokens[0]);
			createFork(bufferTokens);
		}
	}
}
