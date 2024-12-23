#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void forking() {
    pid_t pid;

    
    pid = fork();

    if (pid < 0) { 
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    } else { 
        printf("Parent Process: PID = %d, Created Child PID = %d\n", getpid(), pid);
        wait(NULL);
        printf("Parent Process: Child has terminated.\n");
    }
}

int main() {

    for (int i = 0; i < 3; i++) {
        forking();
    }

    return 0;
}
