#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t childpid; // variable to store the child’s pid
    childpid = fork();
    if(childpid == 0) { // child process
        printf("I am the child process %d\n", getpid());
        execl("run","run", NULL);
        printf("I am the child process!?");
    }
    else if(childpid > 0) { // parent process
        printf("I am the parent process, my first child’s id is: %d\n", childpid);
    }
    printf("Good Bye\n"); // Question?
    return 0;
}