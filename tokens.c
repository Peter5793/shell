#include "shakeup.h"

/**
 * tokenize - tokenize raw user's data
 * @str: user's raw data
 * @delim: delimiters for user's raw input
 * @genHead: general struct
 * Return: string of tokens from users input
 */
char **tokenize(char *str, char *delim, general_t *genHead)
{
	char *current;
	char **tokens;
	int i = 0;

	current = strtok(str, delim);
	tokens = malloc(NUM_TOKENS * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	addMemBufferTokens(genHead, tokens);
	for (i = 0; i < NUM_TOKENS; i++)
	{
		tokens[i] = malloc(100 * sizeof(char));
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
	for (; i < NUM_TOKENS; i++)
		free(tokens[i]);
	return (tokens);
}
