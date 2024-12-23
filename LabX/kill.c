#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Child process: Received signal %d from parent process.\n", sig);
}

int main() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) { 
        printf("Child process: Waiting for signal...\n");
        signal(SIGUSR1, signal_handler);

        
        pause();
        printf("Child process: Exiting.\n");
    } else {
        printf("Parent process: Sending signal to child process.\n");
        sleep(1);
        kill(pid, SIGUSR1);
        wait(NULL);
        printf("Parent process: Child process terminated. Exiting.\n");
    }

    return 0;
}
