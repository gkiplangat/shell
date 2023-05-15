#include "shell.h"


void execmd(char **argv){
    char *comd = NULL, *actual_comd = NULL;;

    if (argv){
        /* get the command from the user */
        comd = argv[0];

        /* generate the path to this command before passing it to execve */
        actual_comd = get_location(comd);

        /* execute the actual command with execve */
        if (execve(actual_comd, argv, NULL) == -1){
            perror("Error:");
        }
    }

}
