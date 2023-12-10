#include "shell.h"

void exit_with_status(int status, char **argv, char *line)
{
	freepointer(argv);
	free(line);
	exit(status);
}

int valid_exit_status(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	while (isspace(*str))
	{
		str++;
	}
	if (*str == '\0')
	{
		return (0);
	}
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	while (*str != '\0')
	{
		if (!isdigit((unsigned char)*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
