#include "shell.h"
void execmd(char **tokens, char *line);
/**
 * execmd - Execute a command given an array of arguments.
 * @tokens: Array of arguments.
 * @line: ===
 */

void execmd(char **tokens, char *line)
{
	pid_t mypid;
	int exit_status;

	mypid = fork();

	if (mypid == 0)
	{
		if (strcmp(tokens[0], "ls") == 0)
		{
			execve("/bin/ls", tokens, environ);
		}
		else
		{
			execve(tokens[0], tokens, environ);
		}

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
		int status;

		waitpid(mypid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0 && (!isatty(STDIN_FILENO)))
			{
				free(line);
				freepointer(tokens);
				exit(exit_status);
			}
			/*exit(exit_status);*/
		}
	}

}
