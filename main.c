#include "main.h"

/**
 * main - A UNIX command line interpreter.
 * @argc: argument count (not used)
 * @argv: argument vector storing the program name at 0 index
 * Return: 0 when succesful
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	size_t i, len = 0;
	char *line = NULL;
	char *args[MAX_COMMAND / 2 + 1];
	ssize_t read;


	/*Invoking an infinte loop*/
	while (1)
	{
		/*The Prompt being flushed to appear on every submission*/
		printf("#cisfun$ ");
		fflush(stdout);

		/*Reads user input*/
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		/*Removes newline character*/
		line[read - 1] = '\0';

		/*Sets the 1st argument to input, NULL terminated*/
		args[0] = line;
		args[1] = NULL;

		/*exit checker*/
		for (i = 0; i < 4; i++)
		{
			if (line[i] != "exit"[i])
				break;
		}
		if (i == 4 && line[4] == '\0')
			break;

		commandExec(args, argv[0]);
	}
	free(line);
	return (0);
}
