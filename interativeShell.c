#include "shakeup.h"

int interactiveShell()
{
	char **bufferTokens, *buffer, *alias;
	size_t len = 101;
	int eof = -1;

	while (1)
	{
		printPrompt("shakeup$");
		buffer = mallocBuffer(len);
		getUserInput(&buffer, &len);
		eof = checkEOF(&buffer);
		bufferTokens = parseBuffer(buffer);
		alias = findAlias(bufferTokens[0]);
		if (alias)
			processAlias(bufferTokens, alias);
		attemptHshCmd(bufferTokens);
		if (correctAbsPath(bufferTokens[0]))
			createFork(bufferTokens, eof);
		else
		{
			bufferTokens[0] = findCmd(bufferTokens[0]);
			createFork(bufferTokens, eof);
		}
	}
}

void processAlias(char **bufferTokens, char *alias)
{
	char *aliasTokens;
	size_t len;

	aliasTokens = tokenize(alias, " ");
	len = arrLen(aliasTokens);
	arrShift(bufferTokens, aliasTokenLen);
	arrPrepend(bufferTokens, aliasTokens, len);
}

int checkEOF(char *buffer)
{
	unsigned int len;

	len = _strlen(buffer);
	if 
}
