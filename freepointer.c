#include "shell.h"

/**
 * freepointer - Free memory associated with an array of strings.
 * @argv: Array of strings to be freed.
 */

void freepointer(char **argv)
{

	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);


}
