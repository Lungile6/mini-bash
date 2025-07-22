#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define BUFSIZE 64

char **parse_input(char *input) {
    int bufsize = BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " ");
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= bufsize) {
            bufsize += BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                perror("realloc failed");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }

    tokens[position] = NULL;
    return tokens;
}