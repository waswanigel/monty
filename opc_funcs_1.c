#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line position
 * @file: poiner to monty file
 * @content: content
 * Return: void
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", opc_push}, {"pall", opc_pall}, {"pint", opc_pint},
		{"pop", opc_pop},
		{"swap", opc_swap},
		{"add", opc_add},
		{"nop", opc_nop},
		{"sub", opc_sub},
		{"div", opc_div},
		{"mul", opc_mul},
		{"mod", opc_mod},
		{"pchar", opc_pchar},
		{"pstr", opc_pstr},
		{"rotl", opc_rotl},
		{"rotr", opc_rotr},
		{"queue", opc_queue},
		{"stack", opc_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * opc_mul - multiplies the values of top two elements of the stack.
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
 * opc_nop- does nothing
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * opc_rotl- rotates the stack up
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
 * opc_rotr- rotates the stack down
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
