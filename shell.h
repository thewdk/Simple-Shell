#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <error.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

int main(int argc, char **argv);
void freepointer(char ***argv);
void execmd(char **argv);
extern char **environ;
void exit_with_status(int status, char **argv, char *line);
int valid_exit_status(const char *str);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* ---------------strings--------------- */
int dtstrlen(char *str);
int dtstrcmp(char *str1, char *str2);
char *dtstrtok(char *str, const char *delimiters);
char *dtstrchr(const char *str, int ch);
char *dtstrcpy(char *strng, int x);

#endif
