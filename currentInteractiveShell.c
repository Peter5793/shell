#include "shakeup.h"

int interactiveShell()
{
	char **bufferTokens, *buffer;
	size_t len = 300;
	int eof = -1;

	while (1)
	{
		printPrompt("shakeup$");
		buffer = mallocBuffer(len);
		getUserInput(&buffer, &len);
		eof = checkEOF(buffer);
		bufferTokens = parseBuffer(buffer);
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
