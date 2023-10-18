#include "monty.h"

/**
 * f_pall - Print all elements in the stack
 * @head: Pointer to the top of the stack
 * @counter: Line number (not used)
 *
 * Description: This function prints all elements in the stack starting from
 * the top.
 *
 * Return: None
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current;
    (void)counter;

    current = *head;
    if (current == NULL)
        return;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * f_swap - Swap the first two elements of the stack
 * @head: Pointer to the top of the stack
 * @counter: Line number
 *
 * Description: This function swaps the positions of the first two elements in
 * the stack.
 *
 * Return: None
 */
void f_swap(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int length = 0, temp;

    current = *head;
    while (current)
    {
        current = current->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    current = *head;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}

