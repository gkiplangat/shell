#include "shell.h"
#include <stdlib.h>

/**
 * exit_shell - exit shell
 * Return: 0 success
 */

void exit_shell(void)
{
	write(STDOUT_FILENO, "Exiting ...\n", 12);
	exit(0);
}
