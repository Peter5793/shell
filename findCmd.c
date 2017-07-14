#include "shakeup.h"

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0, j;
	char *token;

	token = strtok(&(environ[0][0]), "=");

	while (environ[i])
	{
		if (strcmp(token, name) == 0)
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

char *findCmd(char *b)
{
	char *hshPath, *token, *slash = "/", *t = NULL;
	struct stat st;
	int count1;

	hshPath = _getenv(HSHPATH);
	token = strtok(hshPath, "="); /*remove PATH text*/
	for(token = strtok(NULL, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		count1 = _strlen(token) + _strlen(slash) + _strlen(b) + 1;

		t = malloc(count1 * sizeof(char));

		t = __strcat(t, token);
		t = __strcat(t, slash);
		t = __strcat(t, b);

		if (stat(t, &st) == 0)
		{
			printf("FOUND:%s\n", t);
			return (t);
		}
	}
	if(token == NULL)
		return (NULL);
	return (t);
}

int main(void)
{
        char *buffer, **tokens;
        size_t len = 300, i;

        buffer = mallocBuffer(len);
        getUserInput(&buffer, &len);
        tokens = parseBuffer(buffer);
	tokens[0] = findCmd(tokens[0]);

	for (i = 0; tokens[i]; i++)
		printf("Token %zu: %s, address: %p\n", i, tokens[i], (void *)tokens[i]);
        return (0);
}
