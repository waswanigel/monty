#include "monty.h"

/**
 * opc_swap - adds valuew of top two elements of the stack
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_swap(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

/**
 * opc_sub- subtract value
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

/**
 * opc_stack - prints the top value of a stack
 * @head: stack head
 * @counter: line position
 * Return: void
 */
void opc_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.is_lifi = 0;
}

/**
 * opc_queue - prints the top value of queue
 * @head: stack head
 * @counter: lines
 * Return: void
 */
void opc_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.is_lifi = 1;
}

/**
 * addqueue - add node at the tail
 * @n: new value for node
 * @head: head of stack
 * Return: void
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
		aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}


