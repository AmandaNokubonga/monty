#include "monty.h"
global_var var_global;
/**
 * main - Entry point for the Monty program.
 * @ac: Number of command-line arguments
 * @av: Array of command-line arguments, including the opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);
    free_dlistint(stack);
	return (0);
}
