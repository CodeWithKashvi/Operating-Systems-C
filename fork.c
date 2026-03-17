//Write a C program using fork() to create two child processes from a single parent process. 
//Each process should print its process id and parent process id.

#include <stdio.h>
#include <unistd.h>

int main() {
    fork();  // first child
    fork();  // second child

    printf("PID: %d, PPID: %d\n", getpid(), getppid());

    return 0;
}
