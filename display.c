#include "monty.h"

/**
 * f_pchar - Print the character at the top of the stack.
 * @head: A pointer to the stack.
 * @counter: Line counter.
 *
 * This function prints the character value at the top of the stack. If the
 * stack is empty or if the value is out of the ASCII range (0-127), an error
 * message is displayed, and the program exits with an error status.
 */
void f_pchar(stack_t **head, unsigned int counter)
{
    stack_t *h;

    h = *head;
    if (!h)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    if (h->n > 127 || h->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", h->n);
}

