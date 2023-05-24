#include "shell.h"

/**
 * execmd - execute command
 * @argv: - argument vector with command
 * Return: 0 on success
 */

void execmd(char *argv[])
{
	char *comd = NULL;

	if (argv)
	{
	comd = argv[0];
	if (execve(comd, argv, NULL) == -1)
	{
	perror("Error: failed to execute, recheck your command.");

	exit(1);  /* Exit child process on error */
	}
	}
		
}

