#include "shell.h"

int main(int argc, char **argv)
{
	char *token;
	int bytes = 0;
	int i = 0;
	char *line = NULL;
	size_t buf = 0;

	(void)argc;

	while (1)
	{
		argv = malloc(sizeof(char *) * 50);
		write(1, "Sshell$ ", 8);

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
		
		execmd(argv);
		if (argv[0] == NULL)
		{
			freepointer(argv);
			continue;
		}
		if (strcmp(argv[0], "exit") == 0)
		{
			freepointer(argv);
			break;
		}
		i = 0;
		while (argv[i])
		{
			write(1, argv[i], strlen(argv[i]));
			write(1, "\n", 1);
			i++;
		}
		freepointer(argv);
	}
	free(line);
	return (0);
}
