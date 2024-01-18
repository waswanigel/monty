<<<<<<< HEAD
=======
#include "monty.h"
>>>>>>> 95aa80a2711f69029bcf3c0a11e447a6d525bc4c
#define _POSIX_C_SOURCE 200809L
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
<<<<<<< HEAD
=======

>>>>>>> 95aa80a2711f69029bcf3c0a11e447a6d525bc4c
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
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
		free(buffer);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
