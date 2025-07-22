#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "parser.h"
#include "executor.h"

int main() {
    char *input;
    char **args;

    while (1) {
        printf("mini-shell> ");
        input = read_input();
        args = parse_input(input);
        execute_command(args);

        free(input);
        free(args);
    }

    return 0;
}