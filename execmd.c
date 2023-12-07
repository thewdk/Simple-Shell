#include "shell.h"

void execmd(char **argv)
{
	pid_t mypid;
	int status;

	mypid = fork();

	if (mypid == 0)
	{
		if (strcmp(argv[0], "ls") == 0)
		{
			execve("/bin/ls", argv, environ);
		}
		else
			execve(argv[0], argv, environ);

		write(2, "./hsh:", 6);
		write(2, " 1: ", strlen(" 1: "));
		write(2, argv[0], strlen(argv[0]));
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
