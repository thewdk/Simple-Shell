#include "shell.h"

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
