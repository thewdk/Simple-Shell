#include "shell.h"

/**
 * freepointer - Free memory associated with an array of strings.
 * @tokens: Array of strings to be freed.
 */

void freepointer(char **tokens)
{

	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);


}
