#include "shakeup.h"
/**
 * mallocBuffer - creates memory space as requested
 * @length: length of requested buffer size
 * @genHead: main struct for vars
 * Return: pointer to new memory
 */
char *mallocBuffer(size_t length, general_t *genHead)
{
	char *buf;

	buf = malloc(length);
	if (buf == NULL)
		perror("Couldn't malloc the buffer to get user input");
	addMemAddress(genHead, (void *)buf);
	return (buf);
}
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
	addMemAddress(genHead, (void *)buffer);
	return (buffer);
}
/**
 * checkEOF - check for End-Of-File character
 * @buffer: user's input
 * Return: length of buffer or -1 if error
 */
int checkEOF(char *buffer)
{
	unsigned int len;

	len = _strlen(buffer);
	if ((len >= 2) && (buffer[len - 1] == '4') && (buffer[len - 2] == '4'))
		return (0);
	return (-1);
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
