#include "shell.h"

char *get_location(char *comd)
{
    char *get_path, *get_path_copy, *get_path_token, *get_file_path;
    int command_length, directory_length;
    struct stat buffer;

    get_path = getenv("PATH");

    if (get_path)
    {
        /* Duplicate the path string -> remember to free up memory for this because strdup allocates memory that needs to be freed*/
        get_path_copy = strdup(get_path);
        /* Get length of the command that was passed */
        command_length = strlen(comd);

        /* Let's break down the path variable and get all the directories available*/
        get_path_token = strtok(get_path_copy, ":");

        while (get_path_token != NULL)
        {
            /* Get the length of the directory*/
            directory_length = strlen(get_path_token);
            /* allocate memory for storing the command name together with the directory name */
            get_file_path = malloc(command_length + directory_length + 2); /* NB: we added 2 for the slash and null character we will introduce in the full command */
            /* to build the path for the command, let's copy the directory path and concatenate the command to it */
            strcpy(get_file_path, get_path_token);
            strcat(get_file_path, "/");
            strcat(get_file_path, comd);
            strcat(get_file_path, "\0");

            /* let's test if this file path actually exists and return it if it does, otherwise try the next directory */
            if (stat(get_file_path, &buffer) == 0)
            {
                /* return value of 0 means success implying that the file_path is valid*/

                /* free up allocated memory before returning your file_path */
                free(get_path_copy);

                return (get_file_path);
            }
            else
            {
                /* free up the file_path memory so we can check for another path*/
                free(get_file_path);
                get_path_token = strtok(NULL, ":");
            }
        }

        /* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */
        free(get_path_copy);

        /* before we exit without luck, let's see if the command itself is a file_path that exists */
        if (stat(comd, &buffer) == 0)
        {
            return (comd);
        }

        return (NULL);
    }

    return (NULL);
}
