#include "shakeup.h"

int interactiveShell(general_t *genHead)
{
	char **bufferTokens, *buffer = NULL;
	char *tmp;
	size_t len;

	while (1)
	{
		genHead->nCommands++;
		printPrompt("shakeup$ ");
		buffer = getUserInput(buffer, &len);
		bufferTokens = parseBuffer(buffer, genHead);
		findBuiltin(genHead, bufferTokens[0]);
		if (correctAbsPath(bufferTokens[0]))
			createFork(bufferTokens, genHead);
		else
		{
			tmp = findCmd(bufferTokens[0], genHead);
			if (tmp)
				bufferTokens[0] = tmp;
			createFork(bufferTokens, genHead);
		}
	}
	return (0);
}
