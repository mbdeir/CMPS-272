#include<stdio.h>
#include<unistd.h>
int main() {
    fork();
    execl("/bin/ls", "ls", "-l", NULL);
    printf("Hello\n");
}