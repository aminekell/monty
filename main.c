#include "monty.h"
stack_t *global_head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argument_count, char *argument_values[])
{
    if (argument_count != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argument_values[1]);
    free_nodes();
    return (0);
}

/**
 * create_node - Creates a node.
 * @value: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise, NULL.
 */
stack_t *create_node(int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
        err(4);
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->n = value;
    return (new_node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
    stack_t *temporary_node;

    if (global_head == NULL)
        return;

    while (global_head != NULL)
    {
        temporary_node = global_head;
        global_head = global_head->next;
        free(temporary_node);
    }
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_number: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
    stack_t *temporary_node;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    if (global_head == NULL)
    {
        global_head = *new_node;
        return;
    }
    temporary_node = global_head;
    while (temporary_node->next != NULL)
        temporary_node = temporary_node->next;

    temporary_node->next = *new_node;
    (*new_node)->prev = temporary_node;
}
