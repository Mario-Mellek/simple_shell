#include "main.h"

/**
 * env_checker - Prints the current environment variables.
 * @line: User input.
 * Return: 1 if the user entered the 'env' command, 0 otherwise.
 */

int env_checker(char *line)
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		if (line[i] != "env"[i])
			break;
	}
	if (i == 3 && line[3] == '\0')
	{
		while (*environ)
		{
			printf("%s\n", *environ++);
		}
		return (1);
	}
	return (0);
}
