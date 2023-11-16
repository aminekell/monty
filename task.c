#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, int value, unsigned int line_number) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
    (void)line_number;
}

int main(int argc, char *argv[]) {
    FILE *file;
    stack_t *stack = NULL;
    char line[100];
    unsigned int line_number = 1;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        char *opcode, *value_str;
        int value;

        line[strcspn(line, "\n")] = '\0'; /* Remove newline character */
        opcode = strtok(line, " ");
        if (opcode != NULL) {
            if (strcmp(opcode, "push") == 0) {
                value_str = strtok(NULL, " ");
                if (value_str == NULL || sscanf(value_str, "%d", &value) != 1) {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    return EXIT_FAILURE;
                }
                push(&stack, value, line_number);
            } else if (strcmp(opcode, "pall") == 0) {
                pall(&stack, line_number);
            } else {
                fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
                return EXIT_FAILURE;
            }
        }
        line_number++;
    }

    fclose(file);
    return EXIT_SUCCESS;
}

