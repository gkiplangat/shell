#include "shell.h"

/**
 * main - Entry point
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success
*/

int main(int ac, char **argv){
    /*create variable that will hold the prompt*/
    char *prompt = "(ourshell)$ ";
    char *lineptr;
    size_t n = 0;
    ssize_t chars_read = 0;

    /*declare unused variables*/
    (void) ac;
    (void) argv;

    while(1){
    write(STDOUT_FILENO, prompt, strlen(prompt));
    chars_read = getline(&lineptr, &n, stdin);
    /**
     * check whether ther is an error
    */
    if(chars_read == -1)
    {
        write(STDOUT_FILENO,"Error, exiting shell..\n", 23);
        return (-1);
    }

    write(STDOUT_FILENO, lineptr,strlen(lineptr));

    free(lineptr);
    }
return(0);
}