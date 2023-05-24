#include "shell.h"

/* Function declarations */
void exit_shell(void);
void print_environment(void);
void execute_command(char **cmd_tokens);

/**
 * main - The main function that runs the simple shell
 * @ac: The number of arguments passed
 * @argv: Array of pointers to arguments passed
 * Return: Always 0 on success
*/

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nChars_read;
	char *lineptrCopy = NULL;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/* declaring void variables */
	(void)ac;

	/*create a loop for prompt*/
	while (1)
	{
		printf("$", prompt);
	nChars_read = getline(&lineptr, &n, stdin);

	if (nChars_read == -1)
	{
		printf("Exiting ...\n");
		return (-1);
	}

	/*allocate space for a copy  of the lineptr*/
	lineptrCopy = malloc(sizeof(char) * nChars_read);

	if (lineptr == NULL)
	{
		printf("Error:memory allocation");
		return (-1);
	}

	/*copy lineptr to lineptrCopy*/
	strcpy(lineptrCopy, lineptr);

	/* split  the string (lineptr) into an array of words*/
	/* calculate the total number of tokens*/
	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	/*Allocate space to hold the array of strings*/
	argv = malloc(sizeof(char *) * num_tokens);

	/*Store each token in the argv array*/
	token = strtok(lineptrCopy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	execmd(argv);

	/* printf("%s\n", lineptr); */

	/* free up allocated memory*/
	free(lineptr);
	free(lineptrCopy);
	
	}

	return (0);
}
