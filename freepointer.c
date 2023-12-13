#include "shell.h"

/**
 * freepointer - Free memory associated with an array of strings.
 * @argv: Array of strings to be freed.
 */

void freepointer(char ***argv)
{

	int i = 0;

	if (*argv != NULL)
	{
		for (i = 0; (*argv)[i] != NULL; i++)
		{
			free((*argv)[i]);
		}
		free(*argv);
		*argv = NULL;
	}
}
