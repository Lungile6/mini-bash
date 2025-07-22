#include <stdio.h>
#include <stdlib.h>
#include "input.h"

char *read_input() {
    char *input = NULL;
    size_t len = 0;
    ssize_t nread = getline(&input, &len, stdin);

    if (nread == -1) {
        perror("getline failed");
        exit(EXIT_FAILURE);
    }

    if (input[nread - 1] == '\n') {
        input[nread - 1] = '\0';
    }

    return input;
}