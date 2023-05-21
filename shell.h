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
extern char **environ;
void print_environment(void);
void exit_shell(void);
void print_environment(void);
void execute_command(char **cmd_tokens);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

#endif
