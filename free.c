#include "shakeup.h"

/**
 * freeEnv - free environment data struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeEnv(general_t *genHead)
{
	unsigned int i;

	for (i = 0; genHead->_env[i]; i++)
		free(genHead->_env[i]);
	free(genHead->_env);
}

/**
 * freeBufferTokens - Frees all buffer tokens
 * @genHead: Pointer to main struct
 *
 * Return: None
 */
void freeBufferTokens(general_t *genHead)
{
	unsigned int i;

	for (i = 0; genHead->bufferTokens[i]; i++)
		free(genHead->bufferTokens[i]);
	free(genHead->bufferTokens);
}

/**
 * freeBuffer - Frees interactive and non-interactive buffer
 * @buf: The char pointer(s) in gen struct
 *
 * Return: None
 */
void freeBuffer(char *buf)
{
	if (buf == NULL)
		return;
	free(buf);
}

/**
 * freeBuiltins - Frees all of the builtins
 * @genHead: The general struct
 *
 * Return: None
 */
void freeBuiltins(general_t *genHead)
{
	free(genHead->builtins);
}

/**
 * freeStruct - free main program general_t struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeStruct(general_t *genHead)
{
	if (genHead == NULL)
		return;
	freeEnv(genHead);
	freeBufferTokens(genHead);
	freeBuiltins(genHead);
	free(genHead);
}
