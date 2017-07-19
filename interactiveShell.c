#include "shakeup.h"
/**
 * interactiveShell - processes all interactive shell commands
 * @genHead: general struct
 * Return: Always 0.
 */
int interactiveShell(general_t *genHead)
{
	char **bufferTokens, *buffer = NULL;
	char *tmp;
	size_t len;

	while (1)
	{
		genHead->nCommands++;
		printPrompt("shakeup$ ");
		buffer = getUserInput(buffer, &len, genHead);
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
