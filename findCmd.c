#include "shakeup.h"
/**
 * findCmd - finds the command in the possible paths from the PATH env var
 * @b: buffer of entir PATH environment variable
 * Return: string that returns PATH concatenated with command if found
 */
char *findCmd(char *b)
{
	char *hshPath, *tmpPath, *token, *slash = "/", *t = NULL, *tmpToken;
	struct stat st;
	int count1 = 0;

	hshPath = _getenv(HSHPATH);
	tmpPath = malloc(_strlen(hshPath) * sizeof(char) + 1);
	if (tmpPath == NULL)
		return (NULL);
	tmpPath = __strcat(tmpPath, hshPath);
	tmpToken = malloc(_strlen(b) * sizeof(char) + 1);
	if (tmpToken == NULL)
		return (NULL);
	tmpToken = __strcat(tmpToken, b);
	token = strtok(tmpPath, "="); /*remove PATH text*/
	for (token = strtok(NULL, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		count1 = _strlen(token) + _strlen(slash) + _strlen(b) + 1;
		t = malloc(count1 * sizeof(char));
		if (t == NULL)
			return (NULL);
		t = __strcat(t, token);
		t = __strcat(t, slash);
		t = __strcat(t, b);
		if (stat(t, &st) == 0)
		{
			free(tmpPath);
			free(tmpToken);
			return (t);
		}
		free(t);
	}
	free(tmpPath);
	return (tmpToken);
}
