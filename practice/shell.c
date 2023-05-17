#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @argv: argument vector
 */
int main(int ac, char **argv)
{
    char *prompt = "(Ourshell) $ ";
    size_t len = strlen(prompt);
    ssize_t written;
    char *line = NULL;
    size_t line_size = 0;
    ssize_t line_len;

    written = write(STDOUT_FILENO, prompt, len);

    if (written != (ssize_t)len) {
        perror("Error writing prompt to console");
        exit(EXIT_FAILURE);
    }

    while ((line_len = getline(&line, &line_size, stdin)) != -1) {
        // Remove newline character from the end of the line
        if (line[line_len - 1] == '\n') {
            line[line_len - 1] = '\0';
        }

        // Parse the command and arguments
        char *tokens[100]; // Maximum 100 tokens
        char *token = strtok(line, " ");
        int i = 0;

        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }

        tokens[i] = NULL; // Set last token to NULL

        // Execute the command
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            int ret = execvp(tokens[0], tokens);

            if (ret < 0) {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }

            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }

        // Write the prompt to the console again
        written = write(STDOUT_FILENO, prompt, len);

        if (written != (ssize_t)len) {
            perror("Error writing prompt to console");
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    return 0;
}
