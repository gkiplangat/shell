/* Function declarations */
void exit_shell(void);
void print_environment(void);
void execute_command(char **cmd_tokens);

#include "shell.h"

/**
 * main - The main function that runs the simple shell
 * @ac: The number of arguments passed
 * @argv: Array of pointers to arguments passed
 * Return: Always 0 on success
*/

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *linePointer = NULL;
	size_t bufferSize = 0;
	ssize_t characters_read;
	char *linePointerCopy = NULL;
	const char *delimeter = " \n";
	int numberOfTokens = 0;
	char *token;
	int a;

	/* declaring void variables */
	(void)ac;

	/*create a loop for prompt*/
	while (1)
	{
	printf("%s", prompt);
	characters_read = getline(&linePointer, &bufferSize, stdin);

	if (characters_read == -1)
	{
		printf("Exiting ...\n");
		return (-1);
	}

	/*allocate space for a copy  of the linePointer*/
	linePointerCopy = malloc(sizeof(char) * characters_read);

	if (linePointer == NULL)
	{
		perror("tsh:memory allocation error");
		return (-1);
	}

	/*copy linePointer to linePointerCopy*/
	strcpy(linePointerCopy, linePointer);

	/* split  the string (linePointer) into an array of words*/
	/* calculate the total number of tokens*/
	token = strtok(linePointer, delimeter);

	while (token != NULL)
	{
		numberOfTokens++;
		token = strtok(NULL, delimeter);
	}
	numberOfTokens++;

	/*Allocate space to hold the array of strings*/
	argv = malloc(sizeof(char *) * numberOfTokens);

	/*Store each token in the argv array*/
	token = strtok(linePointerCopy, delimeter);

	for (a = 0; token != NULL; a++)
	{
		argv[a] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[a], token);

		token = strtok(NULL, delimeter);
	}
	argv[a] = NULL;

	execmd(argv);

	/* printf("%s\n", linePointer); */

	/* free up allocated memory*/
	free(linePointer);
	}

	return (0);
}
