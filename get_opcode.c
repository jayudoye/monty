#include "monty.h"

/**
 * get_opcode - selects the opcode based on
 * token inputed
 *
 */

void get_opcode(void)
{
	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add},
		{"nop", &nop}, {NULL, NULL}
	};
	int i;

	if (arguments->no_tokens == 0)
		return;

	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, arguments->tokens[0]) 
			== 0)
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
		i++;
	}

	invalid_opcode();

}

/**
 * run_opcode - runs the selected opcode
 *
 */

void run_opcode(void)
{
	stack_t *stack = NULL;

	if (arguments->no_tokens == 0)
		return;
	arguments->instruction->f(&stack, arguments->line_number);
}
