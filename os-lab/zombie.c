#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Process creation failed\n");
        exit(1);
    }
    else if (pid > 0) {
	   sleep(10);
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        
    }
    else {
        printf("Child process\n");
        printf("Child PID: %d\n", getpid());
        printf("Child is exiting...\n");
        exit(0);
    }
    return 0;
}

