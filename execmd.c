#include "shell.h"

void execmd(char **argv)
{
	char *command = "/bin/ls";

	*argv[] = {command, NULL};

	if (execve(command, argv, NULL) == -1)
	{
		perror("Error:");
		return (1);
	}
	return (0);
}
