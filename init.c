#include "shakeup.h"

_builtins_t *initBuiltins(general_t *genHead)
{
	int numCommands = 5;
	_builtins_t *b;

	b = malloc(numCommands * sizeof(_builtins_t));
	if (b == NULL)
		return (NULL);
	addMemAddress(genHead, (void *)b);

        b[0].command = "env";
        b[0].f = runEnv;
        b[1].command = "exit";
        b[1].f = runExit;
        b[2].command = "setenv";
        b[2].f = runSetenv;
        b[3].command = "unsetenv";
        b[3].f = runUnsetenv;
	b[4].command = NULL;
	b[4].f = NULL;
        return (b);
}

general_t *initStruct(char **env, general_t *genHead)
{
	general_t *uno;
	int i = 0;

	uno = malloc(sizeof(general_t));
	if (uno == NULL)
	{
		perror("main struct failed");
		return (NULL);
	}
	addMemAddress(genHead, (void *)uno);

	uno->_env = malloc(ENVSIZE * sizeof(char));
	if (uno->_env == NULL)
	{
		perror("Environment malloc failed");
		return (NULL);
	}
	addMemAddress(genHead, (void *)uno->_env);
	while(env[i])
	{
		uno->_env[i] = env[i];
		i++;
	}

	uno->nCommands = 0;
	uno->head = NULL;
	return (uno);
}
