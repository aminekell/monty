#include "monty.h"

void do_nothing(stack_t **stack_ptr, unsigned int line_num)
{
    (void)stack_ptr;
    (void)line_num;
}

void swap_stack_nodes(stack_t **stack_ptr, unsigned int line_num)
{
    stack_t *temp;

    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL)
        more_err(8, line_num, "swap");

    temp = (*stack_ptr)->next;
    (*stack_ptr)->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = *stack_ptr;
    temp->next = *stack_ptr;
    (*stack_ptr)->prev = temp;
    temp->prev = NULL;
    *stack_ptr = temp;
}

void add_stack_nodes(stack_t **stack_ptr, unsigned int line_num)
{
    int total;

    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL)
        more_err(8, line_num, "add");

    (*stack_ptr) = (*stack_ptr)->next;
    total = (*stack_ptr)->n + (*stack_ptr)->prev->n;
    (*stack_ptr)->n = total;
    free((*stack_ptr)->prev);
    (*stack_ptr)->prev = NULL;
}

void sub_stack_nodes(stack_t **stack_ptr, unsigned int line_num)
{
    int total;

    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL)
        more_err(8, line_num, "sub");

    (*stack_ptr) = (*stack_ptr)->next;
    total = (*stack_ptr)->n - (*stack_ptr)->prev->n;
    (*stack_ptr)->n = total;
    free((*stack_ptr)->prev);
    (*stack_ptr)->prev = NULL;
}

void div_stack_nodes(stack_t **stack_ptr, unsigned int line_num)
{
    int total;

    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL)
        more_err(8, line_num, "div");

    if ((*stack_ptr)->n == 0)
        more_err(9, line_num);

    (*stack_ptr) = (*stack_ptr)->next;
    total = (*stack_ptr)->n / (*stack_ptr)->prev->n;
    (*stack_ptr)->n = total;
    free((*stack_ptr)->prev);
    (*stack_ptr)->prev = NULL;
}
