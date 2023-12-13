#include "shell.h"

/**
 * exit_with_status - Free memory and exit with the specified status.
 * @status: Exit status.
 * @argv: Array of strings to be freed.
 * @line: String to be freed.
 */
void exit_with_status(int status, char **argv, char *line)
{
	freepointer(argv);
	free(line);
	exit(status);
}


/**
 * valid_exit_status - Check if a string represents a valid exit status.
 * @str: String to be checked.
 * Return: 1 if valid, 0 otherwise.
 */
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
