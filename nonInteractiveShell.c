#include "shakeup.h"

int nonInteractiveShell(char *buffer, general_t *genHead)
{
	char **bufferTokens;
	char *tmp;

	genHead->nCommands++;
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
	return (0);
}
