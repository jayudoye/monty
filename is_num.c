#include "monty.h"

/**
 * is_num - checks if current token is a valid number
 * @s: the string to check
 *
 * Return: 1 if true, 0 otherwise
 */

int is_num(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (i == 0 && s[i] == '-' && s[i + 1])
		{
			i++;
			continue;
		}
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;

	}
	return (1);
}
