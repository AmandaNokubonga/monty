#include "monty.h"

/**
 * free_stack - Frees a doubly linked list representing a stack.
 * @head: Pointer to the first node of the stack.
 * Return: No return value.
 */

void free_stack(stack_t *head)
{
    stack_t *temp;

    temp = head;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

/**
 * f_stack - Dummy function for freeing the stack (not used).
 * @head: Pointer to the first node (unused).
 * @counter: Line counter (unused).
 *
 * Return: No return value.
 */

void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;

    bus.lifi = 0;
}
