#include <stdio.h>   // for printf(), fprintf()
#include <stdlib.h>  // for exit(), malloc(), free()
#include <string.h>  // for strcmp()
#include <unistd.h>  // for chdir(), perror()
#include "input.h"
#include "parser.h"
#include "executor.h"

void handle_builtin(char **args) {
    if (args[0] == NULL) return;

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "mini-shell: expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
    } else if (strcmp(args[0], "exit") == 0) {
        printf("Exiting mini-shell. See you, Lungile!\n");
        exit(0);
    } else if (strcmp(args[0], "help") == 0) {
        printf("🚀 Mini Shell Help:\n");
        printf("  cd [dir]   - Change directory\n");
        printf("  exit       - Exit the shell\n");
        printf("  help       - Show this help message\n");
        printf("  Any other command runs as external (e.g., ls, pwd, echo)\n");
    }
}

int main() {
    char *input;
    char **args;

    while (1) {
        printf("mini-shell> ");
        input = read_input();
        if (input == NULL) {
            fprintf(stderr, "Error reading input\n");
            continue; // Handle input read error
        }

        args = parse_input(input);
        if (args == NULL) {
            fprintf(stderr, "Error parsing input\n");
            free(input);
            continue; // Handle parsing error
        }

        if (args[0] == NULL) {
            // Empty input
            free(input);
            free(args);
            continue;
        }

        if (strcmp(args[0], "cd") == 0 || strcmp(args[0], "exit") == 0 || strcmp(args[0], "help") == 0) {
            handle_builtin(args);
        } else {
            execute_command(args);
        }

        free(input);
        free(args);
    }

    return 0;
}