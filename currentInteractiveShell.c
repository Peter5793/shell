#include "shakeup.h"

int interactiveShell(char **env)
{
	char **bufferTokens, *buffer = NULL;
	size_t len;
	general_t *vars;

	vars = initStruct(env);
	vars->builtins = initBuiltins();
	while (1)
	{
		printPrompt("shakeup$ ");
		buffer = getUserInput(buffer, &len);
		bufferTokens = parseBuffer(buffer);
		findBuiltin(vars->builtins, bufferTokens[0]);
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
