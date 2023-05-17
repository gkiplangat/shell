#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

void execmd(char *argv[]);
char *get_location(char *command);
void exit_shell();

#endif
