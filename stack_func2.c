#include "monty.h"
/**
 * _swap - Exchange the top two stack elements.
 * @stack: Pointer to Monty stack list
 * @line_number: Line number of the opcode occurrence
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * _add - Perform addition on the top two stack elements.
 * @stack: Pointer to Monty stack list
 * @line_number: Line number of the opcode occurrence
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * _nop - nothing with top two elements on stacks
 * @stack: pointer to monty stack list
 * @line_number: Line number where this opcode is encountered
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - Output the ASCII value corresponding 
 * to the integer at the top of the stack.
 * @stack: pointer to the stack's top
 * @line_number: line number in the program
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - Determine if an integer is an alphabet character.
 * @c: The integer to check
 * Return: 1 if it's an alphabet character, 0 if it's not
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
