#include "monty.h"

void add_to_stack(stack_t **new_elem, __attribute__((unused))unsigned int line_num)
{
    stack_t *temp;

    if (new_elem == NULL || *new_elem == NULL)
        exit(EXIT_FAILURE);
    if (head == NULL)
    {
        head = *new_elem;
        return;
    }
    temp = head;
    head = *new_elem;
    head->next = temp;
    temp->prev = head;
}

void print_stack(stack_t **stack_ptr, unsigned int line_num)
{
    stack_t *temp;

    (void) line_num;
    if (stack_ptr == NULL)
        exit(EXIT_FAILURE);
    temp = *stack_ptr;
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

void pop_top(stack_t **stack_ptr, unsigned int line_num)
{
    stack_t *temp;

    if (stack_ptr == NULL || *stack_ptr == NULL)
        more_err(7, line_num);

    temp = *stack_ptr;
    *stack_ptr = temp->next;
    if (*stack_ptr != NULL)
        (*stack_ptr)->prev = NULL;
    free(temp);
}

void print_top(stack_t **stack_ptr, unsigned int line_num)
{
    if (stack_ptr == NULL || *stack_ptr == NULL)
        more_err(6, line_num);
    printf("%d\n", (*stack_ptr)->n);
}
