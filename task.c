#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

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
    (void)line_number;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void execute_opcode(stack_t **stack, char *opcode, int value, unsigned int line_number) {
    if (strcmp(opcode, "push") == 0) {
        push(stack, value, line_number);
    } else if (strcmp(opcode, "pall") == 0) {
        pall(stack, line_number);
    } else {
        fprintf(stderr, "Error: Unknown opcode '%s' at line %u\n", opcode, line_number);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Code to open the file and read line by line*/
    /* Inside the loop, tokenize the line to get opcode and value*/
    /* For example:*/
    /* execute_opcode(&stack, opcode, value, line_number);*/

    return EXIT_SUCCESS;
}
