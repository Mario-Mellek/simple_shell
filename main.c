#include "main.h"

/**
 * main - A UNIX command line interpreter.
 * @argc: argument count (not used)
 * @argv: argument vector storing the program name at 0 index
 * Return: 0 when succesful
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	size_t j, len = 0;
	char *token, *line = NULL;
	char *args[MAX_COMMAND / 2 + 1];
	ssize_t read;

	/*Invoking an infinte loop*/
	while (1)
	{
		/*The Prompt being flushed to appear on every submission*/
		printf("\033[32m#cisfun$\033[0m ");
		fflush(stdout);

		/*Reads user input*/
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		/*tokenize the command*/
		token = strtok(line, " ");
		while (token != NULL && j < MAX_COMMAND / 2)
		{
			args[j++] = token;
			token = strtok(NULL, " ");
		}
		args[j] = NULL;
		/*Removes newline character*/
		line[read - 1] = '\0';
		/*Sets the 1st argument to input, NULL terminated*/
		if (j > 0)
			args[0] = args[0];
		else
			args[0] = line;
		/* Check if the user entered 'exit' */
		if (exit_checker(line))
			break;
		commandExec(args, argv[0]);
	}
	free(line);
	return (0);
}

