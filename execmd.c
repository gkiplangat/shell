#include "shell.h"


void execmd(char *argv[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Error: Fork failed");
        return;
    } else if (pid == 0) {
        /* Child process*/
        char *comd = NULL;
        char *actual_comd = NULL;

        if (argv) {
            comd = argv[0];
            actual_comd = get_location(comd);

            if (execve(actual_comd, argv, NULL) == -1) {
                perror("Error: failed to execute, recheck your command.");
                exit(1);  /* Exit child process on error */
            }
        }
    } else {
        /* Parent process*/
        wait(NULL);  /*Wait for the child process to finish*/
    }
}

