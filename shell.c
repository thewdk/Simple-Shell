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
	char **tokens;
	char *token;
	int bytes = 0;
	int i = 0;
	int j = 0;
	char *line = NULL;
	size_t buf = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		tokens = malloc(sizeof(char *) * 3000);
		if (isatty(STDIN_FILENO) != 0)
			write(1, "($) ", 4);

		bytes = getline(&line, &buf, stdin);
		if (bytes == -1)
		{
			freepointer(tokens);
			break;
		}
		i = 0;
		token = strtok(line, " \n");
		while (token != NULL)
		{
			tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(tokens[i], token);
			i++;
			token = strtok(NULL, " \n");
		}
		tokens[i] = NULL;

		if (tokens[0] == NULL)
		{
			freepointer(tokens);
			continue;
		}
		if (strcmp(tokens[0], "exit") == 0)
		{
			int exit_status = 0;
			char *arg = tokens[1];

			if (arg != NULL)
			{
				int valid = 1;
				int n;

				for (n = 0; arg[n] != '\0'; n++)
				{
					if (!isdigit((unsigned char)arg[n]))
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					write(2, "./hsh:", 6);
					write(2, " 2: ", 4);
					write(2, tokens[0], strlen(tokens[0]));
					write(2, ": Illegal number: ", strlen(": Illegal number: "));
					write(2, arg, strlen(arg));
					write(2, "\n", strlen("\n"));
					exit_status = 2;
				}
				else
				{
					exit_status = atoi(arg);
				}
			}
			freepointer(tokens);
			free(line);
			exit(exit_status);
		}
		if (strcmp(tokens[0], "env") == 0)
		{
			while (environ[j])
			{
				write(1, environ[j],  strlen(environ[j]));
				write(1, "\n",  1);
				j++;
			}
			freepointer(tokens);
			continue;
		}
		execmd(tokens);
		freepointer(tokens);
	}
	free(line);
	return (0);
}
