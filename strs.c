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
