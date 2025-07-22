#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "executor.h"

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int status;
        wait(&status);
    } else {
        perror("fork failed");
    }
}