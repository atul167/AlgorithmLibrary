// https://www.geeksforgeeks.org/zombie-and-orphan-processes-in-c/

// A C program to demonstrate Zombie Process.
// Child becomes Zombie as parent is sleeping when child process exits.

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    // Fork returns process id in parent process
    pid_t child_pid = fork();

    // Parent process
    if (child_pid > 0)
        sleep(50);

    // Child process
    else
        exit(0);

    return 0;
}











// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the child process is running. The child process becomes orphan.

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Create a child process
    int pid = fork();

    if (pid > 0)
        printf("in parent process");

    // Note that pid is 0 in child process and negative if fork() fails
    else if (pid == 0) {
        sleep(30);
        printf("in child process");
    }

    return 0;
}
