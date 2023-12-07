#include "shell.h"

/**
 * dtstrtok - Tokenizes a string based on specified delimiters.
 * @str: The input string to be tokenized.
 * @delimiters: A string containing delimiter characters.
 *
 * Return: Pointer to the next token, or NULL if no more tokens are found.
 */

char *dtstrtok(char *str, const char *delimiters)
{
static char *_lastToken;
_lastToken = NULL;
if (str == NULL)
{
str = _lastToken;
}

while (*str && dtstrchr(delimiters, *str))
{
str++;
}

if (*str == '\0')
{
_lastToken = NULL;
retur NULL;
}

char *_tokenEnd = str;
while (*_tokenEnd && !dtstrchr(delimiters, *_tokenEnd))
{
_tokenEnd++;
}

if (*_tokenEnd != '\0')
{
*_tokenEnd = '\0';
_lastToken = _tokenEnd + 1;
}
else
{
_lastToken = NULL;
}

return (str);
}
