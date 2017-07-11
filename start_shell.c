#include "shakeup.h"

void shakeup_error(char *func_name, char *instance, int code)
{
	const char *error;
	char mut_error[100] = "Error: ";
	char *s;
	unsigned int lenName = 0, lenInstance = 0, i;

	lenName = _strlen(func_name);
	lenInstance = _strlen(instance);

	s = malloc((7 + lenName + lenInstance + 1) * sizeof(char));

	for(i = 0; i < lenName; i++)
		mut_error[7 + i] = func_name[i];
	for(i = 0; i < lenInstance; i++)
		mut_error[7 + lenName + lenInstance] = instance[i];
	instance[i] = '\0';

	error = _strcat(mut_error, s);

	perror(error);

	free(s);
}

/**
 * start_shell - Starts the shell
 *
 * Return: Success (0) or failure (error code)
 *
 */

int start_shell(void)
{
	char *buffer, **tokens, delim[] = " |><";
	ssize_t chars_read;
	size_t len = 100;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("#shakeup$ ");
		buffer = malloc(len);
		if (buffer == NULL)
			perror("Error: start_shell() 1");
		chars_read = getline(&buffer, &len, stdin);
		if (chars_read == -1)
			perror("Error: start_shell() 2");
		tokens = tokenize(buffer, delim);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: start_shell() 3");
			exit(1);
		}
		if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
				perror("Error: start_shell() 4");
		}
		else
			wait(&status);
	}
	return (0);
}
