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
 * struct stack_s - shows doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to previous element of the stack (or queue)
 * @next: points to next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @is_lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int is_lifi;
}  bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void opc_push(stack_t **head, unsigned int number);
void opc_pall(stack_t **head, unsigned int number);
void opc_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void opc_pop(stack_t **head, unsigned int counter);
void opc_swap(stack_t **head, unsigned int counter);
void opc_add(stack_t **head, unsigned int counter);
void opc_nop(stack_t **head, unsigned int counter);
void opc_sub(stack_t **head, unsigned int counter);
void opc_div(stack_t **head, unsigned int counter);
void opc_mul(stack_t **head, unsigned int counter);
void opc_mod(stack_t **head, unsigned int counter);
void opc_pchar(stack_t **head, unsigned int counter);
void opc_pstr(stack_t **head, unsigned int counter);
void opc_rotl(stack_t **head, unsigned int counter);
void opc_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void opc_queue(stack_t **head, unsigned int counter);
void opc_stack(stack_t **head, unsigned int counter);

#endif /* MONTY_H */
