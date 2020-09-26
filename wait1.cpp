#include <stdio.h>    // used for printf
#include <unistd.h>   // used for fork(), usleep;
#include <stdlib.h>   // used for exit();
#include <sys/wait.h> // used for wait(); WEXITSTATUS
int main()
{
    pid_t childpid; // variable to store the child’s pid
    childpid = fork();
    if (childpid == 0) { // child process
        printf("\t%d started work\n", getpid());
        sleep(3);
        printf("\t%d finished work\n", getpid());
        exit(100);
    }
    else if (childpid > 0) { // parent process
        int status;
        printf("%d forked %d\n", getpid(), childpid);
        printf("%d will wait for %d to complete its work\n", getpid(), childpid);
        wait(&status); // or: waitpid(childpid, &status, 0);
        printf("%d got notified by the kernel that %d returned a status of %d\n", getpid(), childpid, WEXITSTATUS(status));
    }
    return 0;
}