#include "monty.h"

/**
 * f_add - Adds the first two elements of the stack.
 * @head: Pointer to pointer to the first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_add(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int length = 0, temp;

    h = *head;
    while (h)
    {
        h = h->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: Can't perform addition, stack is too short.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    temp = h->n + h->next->n;
    h->next->n = temp;
    *head = h->next;
    free(h);
}

/**
 * f_sub - Subtracts the top two elements of the stack.
 * @head: Pointer to pointer to the first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_sub(stack_t **head, unsigned int counter)
{
    stack_t *temp;
    int sub, nd;

    temp = *head;
    for (nd = 0; temp != NULL; nd++)
        temp = temp->next;

    if (nd < 2)
    {
        fprintf(stderr, "L%d: Can't perform subtraction, stack is too short.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = *head;
    sub = temp->next->n - temp->n;
    temp->next->n = sub;
    *head = temp->next;
    free(temp);
}

/**
 * f_mul - Multiplies the first two elements of the stack.
 * @head: Pointer to pointer to the first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_mul(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int length = 0, temp;

    h = *head;
    while (h)
    {
        h = h->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: Can't perform multiplication, stack is too short.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    temp = h->next->n * h->n;
    h->next->n = temp;
    *head = h->next;
    free(h);
}

/**
 * f_div - Divides the first two elements of the stack.
 * @head: Pointer to pointer to the first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int length = 0, temp;

    h = *head;
    while (h)
    {
        h = h->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: Can't perform division, stack is too short.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: Division by zero is not allowed.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = h->next->n / h->n;
    h->next->n = temp;
    *head = h->next;
    free(h);
}

/**
 * f_mod - Computes the modulo of the first two elements in the stack.
 * @head: Pointer to pointer to the first node.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_mod(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int length = 0, temp;

    h = *head;
    while (h)
    {
        h = h->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: Can't compute modulo, stack is too short.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: Division by zero is not allowed.\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = h->next->n % h->n;
    h->next->n = temp;
    *head = h->next;
    free(h);
}

