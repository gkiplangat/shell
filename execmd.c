#include "shell.h"


void execmd(char **argv){
    char *comd = NULL;

    if (argv){
        /* get the command from the user */
        comd = argv[0];

        /* execute with execve */
        if (execve(comd, argv, NULL) == -1){
            perror("Error:");
        };
    }

}
