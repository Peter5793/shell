#include "shakeup.h"

char *findCmd(char *b)
{
	char *hshPath, *tmpPath, *token, *slash = "/", *t = NULL;
	struct stat st;
	int count1;

	hshPath = _getenv(HSHPATH);
	tmpPath = malloc(_strlen(hshPath) * sizeof(char));
	tmpPath = __strcat(tmpPath, hshPath);

	token = strtok(tmpPath, "="); /*remove PATH text*/
	for(token = strtok(NULL, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		count1 = _strlen(token) + _strlen(slash) + _strlen(b) + 1;

		t = malloc(count1 * sizeof(char));

		t = __strcat(t, token);
		t = __strcat(t, slash);
		t = __strcat(t, b);

		if (stat(t, &st) == 0)
		{
			free(tmpPath);
			return (t);
		}
	}
	free(tmpPath);
	if(token == NULL)
		return (NULL);
	return (t);
}
