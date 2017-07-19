#include "shakeup.h"

/**
 * initBuiltins - initialize Builtin struct
 * @genHead: general struct
 * Return: initialized builtin struct
 */
builtins_t *initBuiltins(general_t *genHead)
{
	int numCommands = 5;
	builtins_t *b;

	b = malloc(numCommands * sizeof(builtins_t));
	if (b == NULL)
		return (NULL);
	addMemBuiltins(genHead, b);

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
/**
 * initStruct - initial general struct
 * @env: environment data from shell
 * @genHead: general struct
 * Return: initialized general struct
 */
general_t *initStruct(char **env)
{
	general_t *universal;
	int i = 0;
	unsigned int str_len;
	char **new_env;

	universal = malloc(sizeof(general_t));
	if (universal == NULL)
	{
		perror("main struct failed");
		return (NULL);
	}
	new_env = malloc(ENVSIZE * sizeof(char *));
	if (new_env == NULL)
	{
		perror("Environment malloc failed");
		exit(12);
	}
	addMemEnv(universal, new_env);
	while (env[i])
	{
		str_len = _strlen(env[i]);
		new_env[i] = malloc(++str_len * sizeof(char));
		if (new_env[i] == NULL)
		{
			if (i != 0)
				i--;
			for (; i >= 0; i--)
				free(new_env[i]);
			free(new_env);
			exit(12);
		}
		_strcpy(new_env[i], env[i]);
		i++;
	}
	universal->nCommands = 0;
	return (universal);
}
