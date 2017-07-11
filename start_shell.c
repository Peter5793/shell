#include "shakeup.h"

/**
 * start_shell - Starts the shell
 *
 * Return: Success (0) or failure (error code)
 *
 */

int start_shell(void)
{
	char *buffer, **tokens, delim[] = " |><", prompt[] = "#shakeup$ ";
	ssize_t chars_read;
	size_t len = 100;
	pid_t child_pid;
	int status;

	while (1)
	{
		write(1, &prompt, sizeof(prompt));
		buffer = malloc(len);
		if (buffer == NULL)
			perror("Error: start_shell() 1");
		chars_read = getline(&buffer, &len, stdin);
		if (chars_read == -1)
		{
			buffer[0] = '\n';
			write(1, &(buffer[0]), 1);
			exit(0);
		}
		tokens = tokenize(buffer, delim);
		child_pid = fork();
		if (child_pid == -1)
			perror("Error: start_shell() 2");
		if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
				perror("Error: start_shell() 3");
		}
		else
			wait(&status);
	}
	return (0);
}
