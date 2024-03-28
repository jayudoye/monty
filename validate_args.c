#include "monty.h"

/**
 * validate_args - checks number of CL arguments
 * @argc: number of arguments
 */

void validate_args(int argc)
{
	if (argc == 2)
		return;
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
