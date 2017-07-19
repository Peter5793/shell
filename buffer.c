#include "shakeup.h"

/**
 * getUserInput - gets user input from shell
 * @buffer: where user's input is stored
 * @length: length of user's input
 * Return: pointer to user's input line
 */
char *getUserInput(char *buffer, size_t *length, general_t *genHead)
{
	ssize_t chars_read;

	chars_read = getline(&buffer, length, stdin);
	if ((chars_read == -1) && (!buffer))
	{
		perror("Invalid argument");
		exit(EXIT_FAILURE);
	}
	else if (chars_read == -1 && buffer)
	{
		buffer[0] = '\n';
		write(1, buffer, 1);
		free(buffer);
		exit(0);
	}
	addMemIBuffer(genHead, buffer);
	return (buffer);
}

/**
 * parseBuffer - parse user's input
 * @buffer: user's raw input
 * @genHead: main struct for vars
 * Return: tokenized string of user's input
 */
char **parseBuffer(char *buffer, general_t *genHead)
{
	char *delim = " \t\r\n";
	char **tokens = tokenize(buffer, delim, genHead);

	return (tokens);
}
