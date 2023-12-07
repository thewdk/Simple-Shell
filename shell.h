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

int main(int argc, char **argv);
void freepointer(char **argv);
void execmd(char **argv);
extern char **environ;
void exit_with_status(int status, char **argv, char *line);
int valid_exit_status(const char *str);

#endif
