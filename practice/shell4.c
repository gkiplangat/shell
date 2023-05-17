#include "shell.h"


int main(int ac, char **argv){
  char *prompt = "(Ourshell) $ ";
  char *lineptr;
  size_t n = 0; 
  ssize_t written;

  /* declaring void variables */
  (void)ac; (void)argv;

  /* create an infinite loop */
  while (1){
    write(STDOUT_FILENO, prompt, strlen(prompt));
    written = getline(&lineptr, &n, stdin);
    /* check if the getline function failed or reached EOF or user use CTRL + D */ 
    if (written == -1){
      write(STDOUT_FILENO, "Exiting shell....\n", strlen("Exiting shell....\n"));
      return (-1);
    }

    write(STDOUT_FILENO, lineptr, strlen(lineptr));

    /* free up allocated memory */
    free(lineptr);    
  }

  return (0);
}
