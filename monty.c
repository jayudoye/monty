#include "monty.h"

arg_t *arguments = NULL;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	size_t n = 0;
	ssize_t r;

	validate_args(argc);
	initialize_args();
	get_stream(argv[1]);

	while ((r = getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		arguments->line_number += 1;
		tokens();
		get_opcode();
		run_opcode();
		free_tokens();
	}
	close_stream();
	free_args();

	return (0);
}
