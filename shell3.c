#include "shell.h"

int main(int ac, char **argv){
  /*variables declaration*/
  char *prompt = "(ourshell) $ "; /*Holds the prompt message*/
  /*Buffer to store the what user typed in stdin*/
  char *lineptr = NULL;
  /*Buffer to store the copy of what user typed in stdin*/
  char *lineptr_copy = NULL;
  size_t n = 0; /*size of the memory to be allocated to the buffer*/
  ssize_t written;/*stores the number of characters read by getline*/
  const char *delim = " \n"; /*store delimeters*/
  int ntokens = 0; /*number of tokens*/
  char *tokens; /*tokens generated*/
  int i;

  /* declaring void variables */
  (void)ac; 

  /*creating a while loop*/
  while(1){
    write(STDOUT_FILENO, prompt, strlen(prompt));
    written = getline(&lineptr, &n, stdin);

    /*Check whether it is the End Of File EOF*/
    if (written == -1) {
    perror("Exiting ...");
    return(-1);
  }

  /*allocate space to store lineptr_copy*/
  lineptr_copy = malloc(sizeof(char)* written);

  /*Check wether memory allocation was successfully*/
  if (lineptr_copy== NULL){
        perror("Error: memory allocation failed...\n");
        return (-1);
  }
  /*copy the content of lineptr to lineptr_copy*/
  strcpy(lineptr_copy, lineptr);

  /* split the string into an array of words */
        tokens = strtok(lineptr, delim);

        /* determine number of tokens*/
        while (tokens != NULL){
            ntokens++;
            tokens = strtok(NULL, delim);
        }
        ntokens++;
  /*allocate space to hold array of strings*/
  argv = malloc(sizeof(char *) * ntokens);

  tokens = strtok(lineptr_copy, delim);

        for (i = 0; tokens != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(tokens));
            strcpy(argv[i], tokens);

            tokens = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the command */
        execmd(argv);





  /* write(STDOUT_FILENO, lineptr, strlen(lineptr)); */

  

}
  /*free up the allocated space*/
  free(lineptr);
  free(argv);
  free(lineptr_copy);
  return (0);
}
