#include "monty.h"

/**
 * _pstr -  Print the string from the top of the stack.
 * @stack: Pointer to the Monty stack list
 * @line_number: Line number where this opcode is executed
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - Rotate the top elements of the stack to the left.
 * @stack: Pointer to the Monty stack list
 * @line_number: Line number where this opcode is executed
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * _rotr - Rotate the top elements of the stack to the right.
 * @stack: Pointer to the Monty stack list
 * @line_number: Line number where this opcode is executed
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}
