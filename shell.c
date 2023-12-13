#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of command-line arguments.
 B
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
		argv = malloc(sizeof(char *) * 3000);
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
			int exit_status = 0;
			char *arg = argv[1];

			if (arg != NULL)
			{
				int valid = 1;
				int i;

				for (i = 0; arg[i] != '\0'; i++)
				{
					if (!isdigit((unsigned char)arg[i]))
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					write(2, "./hsh:", 6);
					write(2, " 2: ", 4);
					write(2, argv[0], strlen(argv[0]));
					write(2, ": Illegal nuber: ", strlen(": Illegal nuber: "));
					write(2, arg, strlen(arg));
					write(2, "\n", strlen("\n"));
					exit_status = 2;
				}
				else
				{
					exit_status = atoi(arg);
				}
			}
			freepointer(argv);
			free(line);
			exit(exit_status);
		}
		if (strcmp(argv[0], "env") == 0)
		{
			while (environ[j])
			{
				write(1, environ[j],  strlen(environ[j]));
				write(1, "\n",  1);
				j++;
			}
			freepointer(argv);
			continue;
		}
		execmd(argv);
		freepointer(argv);
	}
	free(line);
	return (0);
}
