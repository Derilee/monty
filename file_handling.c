#include "monty.h"
/**
 * free_varfile - function that frees the global variables
 */
void free_varfile(void)
{
	free_list(varfile.head);
	free(varfile.buffer);
	fclose(varfile.fd);
}

/**
 * start_varfile - function that initializes the global variables
 * @fd: file descriptor
 */
void start_varfile(FILE *fd)
{
	varfile.lifo = 1;
	varfile.cline = 1;
	varfile.arg = NULL;
	varfile.head = NULL;
	varfile.fd = fd;
	varfile.buffer = NULL;
}

/**
 * check_file - function that checks if the file exists
 *              and if the file can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file descriptor
 */
FILE *check_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
