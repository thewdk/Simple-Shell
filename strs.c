#include "shell.h"

/**
 * dtstrchr - Finds the first occurrence of a character in a string.
 * @str: The null-terminated string to be searched.
 * @ch: The character to be located.
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */

char *dtstrchr(const char *str, int ch)
{
while (*str != '\0')
{
if (*str == (char)ch)
{
return ((char *)str);
}
str++;
}
return (NULL);
}


/**
* dtstrlen - calculates a length of a given string
* @str: pointer to chars
* Return: lenght of string
**/
int dtstrlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
* dtstrcmp - compares two strings
* @str1: string 1
* @str2: string 2
* Return: if both strings are same 0, else -1
**/
int dtstrcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
	{
		if (str1[i] == '\0')
			return (1);
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}

/**
* dtstrcpy - copies a given string and returns a copy
* @strng: pointer to chars to be copied
* @x: number of chars to be copied
* Return: pointer to copy
**/
char *dtstrcpy(char *strng, int x)
{
	int y;
	char *res;

	res = malloc(sizeof(res) * (x + 1));
	if (res == NULL)
		return (NULL);
	for (y = 0; y < x; y++)
	{
		res[y] = *strng;
		strng++;
	}
	res[y] = '\0';
	return (res);
}
