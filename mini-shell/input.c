// input.c - Handles reading user input for the mini-shell
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

// Reads a line of input from stdin and returns it as a string
char *read_input() {
    char *input = NULL;
    size_t len = 0;
    ssize_t nread = getline(&input, &len, stdin); // Read line from stdin

    if (nread == -1) {
        perror("getline failed"); // Print error if reading fails
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline character, if present
    if (input[nread - 1] == '\n') {
        input[nread - 1] = '\0';
    }

    return input;
}