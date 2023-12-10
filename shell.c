#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	char *token;
	int bytes = 0;
	int i = 0;
	int j = 0;
	char *line = NULL;
	size_t buf = 0;

	(void)argc;

	while (1)
	{
		argv = malloc(sizeof(char *) * 50);
		if (isatty(STDIN_FILENO) != 0)
			write(1, "($) ", 4);

		bytes = getline(&line, &buf, stdin);
		if (bytes == -1)
		{
			freepointer(argv);
			break;
		}
		i = 0;
		token = strtok(line, " \n");
		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(argv[i], token);
			i++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

		if (argv[0] == NULL)
		{
			freepointer(argv);
			continue;
		}
		if (strcmp(argv[0], "exit") == 0)
		{
			if (argv[1] != NULL)
			{
				int exit_status = atoi(argv[1]);
				if (exit_status < 0 || exit_status > 255)
				{
					write(2, "./hsh: ", 7);
					write(2, argv[0], strlen(argv[0]));
					write(2, ": ", 2);
					write(2, argv[1], strlen(argv[1]));
					write(2, ": numeric argument required\n", strlen(": numeric argument required\n"));
					exit(EXIT_FAILURE);
				}
				else
				{
					exit(exit_status);
				}
				exit_with_status(exit_status, argv, line);
			}
			else
			{
				break;
			}
		}
		if (strcmp(argv[0], "env") == 0)
		{
			while (environ[j])
			{
				write(1, environ[j],  strlen(environ[j]));
				write(1, "\n",  1);
				j++;
			}
			continue;
		}
		execmd(argv);
		freepointer(argv);
	}
	free(line);
	return (0);
}
