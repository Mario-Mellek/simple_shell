#include "main.h"

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
