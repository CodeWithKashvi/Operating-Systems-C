//Write a C program using fork() to create three processes in a linear chain (Parent → Child → Grandchild). 
//Each process should print its PID.

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {  // child
        pid2 = fork();

        if (pid2 == 0) {  // grandchild
            printf("Grandchild PID: %d\n", getpid());
        } else {
            printf("Child PID: %d\n", getpid());
        }
    } else {
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}
