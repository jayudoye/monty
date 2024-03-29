#include "monty.h"

/**
 * tokens - tokenizes line read from file
 */

void tokens(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(linecpy, arguments->line);
	arguments->no_tokens = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->no_tokens += 1;
		token = strtok(NULL, delims);
	}

	arguments->tokens = malloc(sizeof(char *) *
			(arguments->no_tokens + 1));
	strcpy(linecpy, arguments->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->tokens[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (arguments->tokens[i] == NULL)
			malloc_failed();
		strcpy(arguments->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	arguments->tokens[i] = NULL;
	free(linecpy);
}
