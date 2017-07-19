#include "shakeup.h"
#include "errno.h"

/**
 * createFork - run the user's command with fork and execve
 * @bufferTokens: user's command properly formatted
 * @genHead: general struct
 * Return: Always 0
 */
int createFork(char **bufferTokens, general_t *genHead)
{
	pid_t child_pid;
	int status;
	char *tmp = NULL, *tmpNum = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork: Resource temporarily unavailable");
		return (1);
	}
	tmp = malloc(100 * sizeof(char));
	if (tmp == NULL)
		perror("createFork:Could not malloc");
	tmp = __strcat(tmp, bufferTokens[0]);
	if (child_pid == 0)
	{
		if (execve(bufferTokens[0], bufferTokens, genHead->_env) == -1)
		{
			tmpNum = _itoa(genHead->nCommands);
			write(1, "hsh: ", 5);
			write(1, tmpNum, _strlen(tmpNum));
			write(1, ": ", 2);
			write(1, tmp, _strlen(tmp));
			write(1, ": not found\n", 12);
			free(tmp);
			free(tmpNum);
			freeStruct(genHead);
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	else
	{
		wait(&status);
		free(tmp);
	}
	return (0);
}
