#include "shakeup.h"
/**
 * main - hsh simple shell program
 * @argc: number of arguments sent to main program
 * @argv: string of input from users
 * @env: shell environment variables
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *buf;
	ssize_t charsRead;
	general_t *genHead = NULL;

	argc = argc;
	argv = argv;

	genHead = initStruct(env, genHead);
	genHead->builtins = initBuiltins(genHead);

	buf = malloc(1024 * sizeof(char));
	if (buf == NULL)
		exit(12);
	charsRead = read(0, buf, 1024);
	if (charsRead == 0)
	{
		genHead->isInteractive = 1;
		interactiveShell(genHead);
	}
	else
	{
		genHead->isInteractive = 0;
		nonInteractiveShell(buf, genHead);
	}
	free(buf);
	return (0);
}
