#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND 50

extern char **environ;
void commandExec(char *args[]);

/**
 * main - A UNIX command line interpreter.
 * Return: 0 when succesful
 */

int main(void)
{
	size_t i, len = 0;
	char *line = NULL;
	char *args[MAX_COMMAND / 2 + 1];
	ssize_t read;


	/*Invoking an infinte loop*/
	while (1)
	{
		/*The Prompt being flushed to appear on every submission*/
		printf("\033[32m($)\033[0m ");
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

		commandExec(args);
	}
	free(line);
	return (0);
}

/**
 * commandExec - Execustes a command in a child process.
 * @args: Array of strings containing the command.
 */

void commandExec(char *args[])
{
	pid_t pid;

	/*Forks a new process*/
	pid = fork();
	if (pid == 0)
	{
		/*Child process executes the command*/
		execve(args[0], args, environ);
		perror(args[0]);
		exit(0);
	}
	else
	{
		/*Waits for the child process to conclude*/
		wait(NULL);
	}
}
