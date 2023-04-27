#include "main.h"

/**
 * commandExec - Execustes a command in a child process.
 * @args: Array of strings containing the command.
 * @program_name: name of the program passed in from argv[0]
 */

void commandExec(char *args[], char *program_name)
{
	pid_t pid;

	/*Forks a new process*/
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/*Child process executes the command*/
		execve(args[0], args, environ);
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Waits for the child process to conclude*/
		wait(NULL);
	}
}
