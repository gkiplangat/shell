#include "shell.h"

/**
 * print_environment - print enviroment variables
 *
 * Return: void
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}
}

