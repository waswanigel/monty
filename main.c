#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
<<<<<<< HEAD
 * main - interprets monty code
 * @argc: number of arguments
 * @argv: monty file location
=======
 * main - entry point for monty code interpreter
 * @argc: argument count
 * @argv: argument vector
>>>>>>> b639cf6b702d42430f3aa324817814c12a8cd88f
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		buffer = NULL;
		read_line = getline(&buffer, &size, file);
		bus.content = buffer;
		counter++;

		if (read_line > 0)
		{
			execute(buffer, &stack, counter, file);
		}
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	return (0);
}
