#include "monty.h"
/**
 * main - Entry point of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0, if  successful
 */
int main(int argc, char *argv[])
{
	char *lines[2] = {NULL, NULL};
	FILE *fd;
	size_t size = 256;
	ssize_t num = 0;

	fd = check_file(argc, argv);
	start_varfile(fd);
	num = getline(&varfile.buffer, &size, fd);
	while (num != -1)
	{
		lines[0] = _strtokenize(varfile.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", varfile.cline);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_varfile();
				exit(EXIT_FAILURE);
			}
			varfile.arg = _strtokenize(NULL, " \t\n");
			f(&varfile.head, varfile.cline);
		}
		num = getline(&varfile.buffer, &size, fd);
		varfile.cline++;
	}
	free_varfile();
	return (0);
}
