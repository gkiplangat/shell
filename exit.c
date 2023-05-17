#include "shell.h"
#include <stdlib.h>

void exit_shell() {
    write(STDOUT_FILENO, "Exiting ...\n", 12);
    exit(0);
}
