#include "monty.h"

/**
 * f_pstr - Print characters from the stack as a string.
 * @head: A pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 *
 * This function prints characters from the top of the stack until it encounters
 * a non-printable character or the stack is empty. Each character is printed
 * to the standard output.
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

