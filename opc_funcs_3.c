#include "monty.h"

/**
 * opc_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void opc_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
			if (flag == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(bus.file);
				free(bus.content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.is_lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * opc_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void opc_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * opc_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void opc_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * opc_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void opc_pchar(stack_t **head, unsigned int counter)
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
