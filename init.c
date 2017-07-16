_builtins_t *initBuiltins(void)
{
	int numCommands = 8;
	_builtins_t *b;

	b = malloc(numCommands * sizeof(_builtins_t));
	if (b == NULL)
		return (NULL);
	b[0].command = "cd";
	b[0].f = (void *)runCd;
        b[1].command = "env";
        b[1].f = (void *)runEnv;
        b[2].command = "exit";
        b[2].f = (void *)runExit;
        b[3].command = "help";
        b[3].f = (void *)runHelp;
        b[4].command = "history";
        b[4].f = (void *)runHistory;
        b[5].command = "setenv";
        b[5].f = (void *)runSetenv;
        b[6].command = "unsetenv";
        b[6].f = (void *)runUnsetenv;
	b[7].command = NULL;
	b[7].f = NULL;
        return (b);
}

general_t *initStruct(void)
{
	general_t *main;
	char **e = NULL;
	int i;

	main = malloc(sizeof(general_t));
	if(main == NULL)
	{
		perror("main struct failed");
		return(NULL);
	}

	e = malloc(ENVSIZE * sizeof(char));
	if (e == NULL)
		return (NULL);
	while(envir[i])
	{
		e[i] = envir[i];
		printf("old:%s\nnew:%s\n", envir[i], e[i]);
		i++;
	}

	main->nCommands = 0;
	main->head = NULL;
	return (main);
}
