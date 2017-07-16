#include "shakeup.h"
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

void findBuiltin(general_t *vars, char *cmd)
{
	int i = 0;
	_builtins_t *b = vars->builtins;

	while (b[i].command)
	{
		if (_strcmp(cmd, b[i].command) == 0)
		       b[i].f(vars);
		i++;
	}
}
