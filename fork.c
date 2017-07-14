#include "shakeup.h"

int createFork(char **bufferTokens)
{
	pid_t child_pid;
	int status;
	size_t i;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork: Resource temporarily unavailable");
		return (1);
	}
	for (i = 0; bufferTokens[i]; i++)
		printf("CF: Token %zu: %s\n", i, bufferTokens[i]);
	if (child_pid == 0)
	{
		if (execve(bufferTokens[0], bufferTokens, NULL) == -1)
			perror("Create error message with struct");
	}
	else
		wait(&status);
	return (0);
}
