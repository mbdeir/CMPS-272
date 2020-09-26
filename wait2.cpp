#include <stdio.h>    // used for printf
#include <unistd.h>   // used for fork(), usleep;
#include <stdlib.h>   // used for exit();
#include <sys/wait.h> // used for wait(); WEXITSTATUS
int main()
{
    pid_t childpid; // variable to store the child’s pid
    childpid = fork();
    int status;
    if (childpid == 0)
    {
        printf("CHILD: %d\n", getpid());
        usleep(1000000);
        printf("CHILD: %d terminates\n", getpid());
        exit(13);
    }
    else if (childpid > 0)
    {
        pid_t childpid1 = fork();
        if (childpid1 == 0)
        {
            exit(12);
        }
        else
        {
            printf("PARENT\n");
            waitpid(childpid, &status, 0);
            printf("PARENT: my child terminated with status %d\n", WEXITSTATUS(status));
            exit(0);
        }
    }
}