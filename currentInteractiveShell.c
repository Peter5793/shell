#include "shakeup.h"

int interactiveShell(char **env, general_t *genHead)
{
	char **bufferTokens, *buffer = NULL;
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
			bufferTokens[0] = findCmd(bufferTokens[0], genHead);
			createFork(bufferTokens, genHead);
		}
	}
	return (0);
}
