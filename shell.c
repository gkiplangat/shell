#include "shell.h"

/**
 * main -entry point
 * @ac: - argument count
 * @argv: - argument vector
*/

int main(int ac, char **argv){
  char *prompt = "(Ourshell) $ ";
  size_t len = strlen(prompt);
  ssize_t written;

  written = write(STDOUT_FILENO, prompt, len);
  if (written != len) {
      // Handle error here
      return 1;
  }

  return (0);
}

