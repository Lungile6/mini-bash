// parser.c - Handles parsing of user input into command arguments
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define BUFSIZE 64 // Initial buffer size for arguments

// Parses the input string into an array of argument strings
char **parse_input(char *input) {
    int bufsize = BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *)); // Allocate memory for tokens
    char *token;

    if (!tokens) {
        perror("malloc failed"); // Print error if allocation fails
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " "); // Split input by spaces
    while (token != NULL) {
        tokens[position++] = token; // Store each token

        // If buffer is exceeded, reallocate more space
        if (position >= bufsize) {
            bufsize += BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                perror("realloc failed"); // Print error if reallocation fails
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " "); // Get next token
    }

    tokens[position] = NULL; // Null-terminate the array
    return tokens;
}