#include "shell.h"

#define MAX_INPUT_SIZE 100

static void clear_buffer(void);
static void add_to_buffer(char c);
static void remove_from_buffer(void);

/**
 * custom_getline - reads input from the user
 * & dynamically allocates memory for the line
 * return:  the line once a newline/EOF character is encountered
 */

char *custom_getline()
{
	static char buffer[MAX_INPUT_SIZE];
	static int buffer_index;
	static int buffer_size;

	char *line = NULL;
	int line_size = 0;
	int character;

	while (1)
	{
	/* If buffer is empty, read a new chunk of characters */
	if (buffer_index >= buffer_size)
	{
		buffer_size = read(STDIN_FILENO, buffer, MAX_INPUT_SIZE);
		buffer_index = 0;

	/* If read returns 0 (end of file), return NULL to indicate end of input */
	if (buffer_size == 0)
	{
	if (line_size > 0)
	{
		line = realloc(line, (line_size + 1) * sizeof(char));
		line[line_size] = '\0';
	}
		return (line);
		}
	}

	character = buffer[buffer_index++];

	/* If maximum line size is reached, resize the line buffer */
	if (line_size >= MAX_INPUT_SIZE - 1)
	{
		line = realloc(line, (line_size + 2) * sizeof(char));
		line[line_size + 1] = '\0';
	}

	line[line_size++] = character;

	/* If end of line is reached, terminate the line and return it */
	if (character == '\n')
	{
		line = realloc(line, (line_size + 1) * sizeof(char));
		line[line_size] = '\0';
		return (line);
	}
	}
}

/**
 * main: entry point to the program
 * repeatedly promots user for text
 * displays entred text/line
 * Return: 0 if successful
 */

	int main(void)
{
	char *line;
	const char *prompt = "Enter a line: ";
	const int prompt_length = strlen(prompt);
	ssize_t written;

	while (1)
	{
	written = write(STDOUT_FILENO, prompt, prompt_length);

	if (written == -1)
	break;

	line = custom_getline();
	if (line == NULL)
	break;
	write(STDOUT_FILENO, "You entered: ", 13);
	write(STDOUT_FILENO, line, strlen(line));
	write(STDOUT_FILENO, "\n", 1);

	free(line);
	}

	return (0);
}
