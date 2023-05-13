#include "shell.h"

int main(int ac, char **argv){
  /*variables declaration*/
  char *prompt = "(ourshell) $ ";
  char *lineptr;
  size_t n = 0; 
  ssize_t written;

  /* declaring void variables */
  (void)ac; (void)argv;
  /*creating an infinite loop*/
  while(1){
    write(STDOUT_FILENO, prompt, strlen(prompt));
    written = getline(&lineptr, &n, stdin);
    if (written == -1) {
    perror("Exiting ...");
    return(-1);
  }
  write(STDOUT_FILENO, lineptr, strlen(lineptr));

  /*free up the allocated space*/
  free(lineptr);
}
  return (0);
}
