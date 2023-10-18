#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - representation of a doubly linked list for a stack or queue
 * @n: integer data
 * @prev: points to the previous element in the stack or queue
 * @next: points to the next element in the stack or queue
 *
 * Description: This structure defines a node for a doubly linked list, used to
 * implement stack or queue data structures.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its corresponding function
 * @opcode: the opcode as a string
 * @f: the function to execute for the given opcode
 *
 * Description: This structure associates an opcode with its corresponding
 * function for stack and queue operations.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - structure to carry program variables, file, and content
 * @arg: value or argument
 * @file: pointer to the Monty bytecode file
 * @content: line content
 * @lifi: flag indicating stack or queue mode
 *
 * Description: This structure is used to pass various values and flags
 * throughout the Monty program.
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);

char *clean_line(char *content);
void free_stack(stack_t *head);

int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);

void f_add(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);

void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);

void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);

#endif

