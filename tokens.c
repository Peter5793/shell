#include "shakeup.h"

char **tokenize(char *str, char *delim)
{
	char *current;
	char **tokens;
	int i = 0;

	current = strtok(str, delim);
	tokens = malloc(10 * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	for (i = 0; i < 10; i++)
	{
		tokens[i] = malloc(30 * sizeof(char));
		if (tokens[i] == NULL)
		{
			if (i != 0)
				i -= 1;
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
	}
	i = 0;
	while (current)
	{
		if (i > 0)
			current = strtok(NULL, delim);
		tokens[i] = current;
		i++;
	}
	return (tokens);
}
