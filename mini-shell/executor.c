// executor.c - Handles command execution in the mini-shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "executor.h"

// Executes a command using fork and execvp
void execute_command(char **args) {
    pid_t pid = fork(); // Create a new process

    if (pid == 0) {
        // Child process: replace with new program
        execvp(args[0], args);
        perror("execvp failed"); // Print error if exec fails
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process: wait for child to finish
        int status;
        wait(&status);
    } else {
        // Fork failed
        perror("fork failed");
    }
}