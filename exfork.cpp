#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t childpid; // variable to store the child’s pid
    childpid = fork();
    if(childpid == 0) { // child process
        printf("I am the child process %d my parent %d\n", getpid(), getppid());
    }
    else if(childpid > 0) { // parent process
        printf("I am the parent process %d, my first child’s is: %d\n", getpid(), childpid);
    }
    else {
        printf("Error in fork");
    }
    printf("Good Bye\n");
    return 0;
}