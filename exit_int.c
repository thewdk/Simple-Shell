#include "shell.h"

void exit_with_status(int status, char **argv, char *line)
{
	freepointer(argv);
	free(line);
	exit(status);
}

int valid_exit_status(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}
