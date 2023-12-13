#include "shell.h"

/**
 * freepointer - Free memory associated with an array of strings.
 * @argv: Array of strings to be freed.
 */

void freepointer(char ***tokens)
{

	int i = 0;

	if (*tokens != NULL)
	{
		for (i = 0; (*tokens)[i] != NULL; i++)
		{
			free((*tokens)[i]);
		}
		free(*tokens);
		*tokens = NULL;
	}
}
