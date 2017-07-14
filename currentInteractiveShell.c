#include "shakeup.h"

int interactiveShell()
{
	char **bufferTokens, *buffer = NULL;
	size_t len = 300, i;

	while (1)
	{
		printPrompt("shakeup$ ");
		buffer = mallocBuffer(len);
		getUserInput(&buffer, &len);
		bufferTokens = parseBuffer(buffer);
		if (correctAbsPath(bufferTokens[0]))
			createFork(bufferTokens);
		else
		{
			bufferTokens[0] = findCmd(bufferTokens[0]);
			for (i = 0; bufferTokens[i]; i++)
				printf("IS: Token %zu: %s\n", i, bufferTokens[i]);
			createFork(bufferTokens);
		}
	}
}
