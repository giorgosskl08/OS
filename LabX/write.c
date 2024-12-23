#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void write_pid_to_file(const char *message) {
    FILE *file = fopen("pid.txt", "a"); // Open file in append mode
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", message); // Write the message to the file
    fclose(file); // Close the file
}

void forking() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) { // Error in fork
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        char message[100];
        snprintf(message, sizeof(message), "Child Process: PID = %d, Parent PID = %d", getpid(), getppid());
        write_pid_to_file(message); // Write child process info to file
        exit(0); // Exit child process
    } else { // Parent process
        char message[100];
        snprintf(message, sizeof(message), "Parent Process: PID = %d, Created Child PID = %d", getpid(), pid);
        write_pid_to_file(message); // Write parent process info to file
        wait(NULL); // Wait for the child process to finish
    }
}

int main() {
    forking();
    return 0;
}
