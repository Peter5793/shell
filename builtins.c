#include "shakeup.h"
#include "hsh.h"
#include "builtins.h"
/*
char **initEnv(char **envir)
{
	char **e = NULL;
	int i;

	e = malloc(ENVSIZE * sizeof(char));
	if (e == NULL)
		return (NULL);

	while(envir[i])
	{
		e[i] = envir[i];
		printf("old:%s\nnew:%s\n", envir[i], e[i]);
		i++;
	}

	return (e);
}
*/

int findBuiltin(_builtins_t b[], char *cmd)
{
	int i = 0;

	while (b[i].command)
	{
		if (_strcmp(cmd, b[i].command) == 0)
		{
			return (b[i].f());
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	general_t *genHead = NULL;
	list_t *l = NULL;
	char *test1, *test2, *test3;
	char **_env = NULL;
	int test = 0;
	_builtins_t *b;
	char *c = "unsetenv";

	genHead = initStruct();
	if (genHead == NULL)
		return(0);
	test1 = malloc(100 * sizeof(char));
	test2 = malloc(100 * sizeof(char));
	test3 = malloc(100 * sizeof(char));
	addMemAddress(genHead, (void *)test1);

	b = initBuiltins();
	test = findBuiltin(b, c);
	if (test == 0)
		printf("Didn't find command\n");

	printList(genHead);

	free(b);
	freeList(genHead);
	freeStruct(genHead);
	genHead = NULL;

	return(0);
}
