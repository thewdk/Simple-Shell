#include "shell.h"

/**
 * execmd - Execute a command given an array of arguments.
 * @argv: Array of arguments.
 */

void execmd(char **tokens)
{
	pid_t mypid;
	int status;

	mypid = fork();

	if (mypid == 0)
	{
		if (strcmp(tokens[0], "ls") == 0)
		{
			execve("/bin/ls", tokens, environ);
		}
		else
			execve(tokens[0], tokens, environ);

		write(2, "./hsh:", 6);
		write(2, " 1: ", strlen(" 1: "));
		write(2, tokens[0], strlen(tokens[0]));
		write(2, ": not found\n", strlen(": not found\n"));
		exit(EXIT_FAILURE);
	}
	else if (mypid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		int exit_status;

		waitpid(mypid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WIFEXITED(status);
			if (exit_status > 0 && (!isatty(STDIN_FILENO)))
				exit(exit_status);
		}
	}
}
