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

int main(int argc, char **argv);
void freepointer(char **argv);
void execmd(char **argv);
extern char **environ;

#endif
