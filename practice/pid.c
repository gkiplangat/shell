#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
    /*create variables to hold the id*/
    pid_t child_process_id;
    pid_t parent_id;

    /*initialize the variables with their respective values*/
    child_process_id =getpid();
    parent_id =getppid();
    /*print out the IDs*/
    printf("%u\n",child_process_id);
    printf("%u\n",parent_id);
    
    return (0);
}