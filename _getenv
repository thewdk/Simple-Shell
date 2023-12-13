#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found or on error.
 */
char *_getenv(const char *name)
{
	if (name == NULL)
	{
		return NULL;
	}
	for (struct environ_node **env = environ; (*env)->name != NULL; ++env)
	{
		if (strcmp((*env)->name, name) == 0)
		{
			char *value = malloc(strlen((*env)->value) + 1);

			if (value == NULL)
			{
				return (NULL);
			}
			strcpy(value, (*env)->value);
			return (value);
		}
	}
	return (NULL);
}
