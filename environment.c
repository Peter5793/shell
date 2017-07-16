#include "shakeup.h"

extern char **environ;

char *_getenv(char *name)
{
	int i = 0, j;
	char *token;

	token = strtok(&(environ[0][0]), "=");

	while (environ[i])
	{
		if (_strcmp(token, name) == 0)
		{
			for(j = 0; environ[i - 1][j]; j++)
				;
			environ[i - 1][j] = '=';
			return (environ[i - 1]);
		}
		token = strtok(&(environ[i][0]), "=");
		i++;
	}

	return(NULL);
}

void runEnv()
{
	printf("runEnv():\n");
}

void runSetenv()
{
	printf("runSetenv():\n");
}

void runUnsetenv()
{
	printf("runUnsetenv():\n");
}
