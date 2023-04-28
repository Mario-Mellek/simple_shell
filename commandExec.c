#include "main.h"

/**
 * commandExec - Executes a command with arguments.
 * @args: An array of command-line arguments,
 * where the first argument is the command to execute
 * and subsequent arguments are its arguments.
 * @program_name: The name of the program (used for error messages).
 */

void commandExec(char *args[], char *program_name)
{
	pid_t pid;
	char *path = getenv("PATH"); /*path of the command using PATH env var*/
	char *pathCopy = strdup(path);
	char *token, *p = pathCopy;
	char command_path[1024]; /* maximum size of PATH is 1024 in Linux */
	int cmd_exists = 0;

	while ((token = strtok(p, ":")) != NULL) /*Checks each dir in PATH*/
	{
		p = NULL;
		snprintf(command_path, sizeof(command_path), "%s/%s", token, args[0]);
		if (access(command_path, X_OK) == 0)
		{
			cmd_exists = 1;
			break;
		}
	}
	free(pathCopy);
	if (!cmd_exists)
	{
		perror(program_name);
		return;
	}
	pid = fork(); /*Forks a new process*/

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(command_path, args, environ); /*Execute in the child process*/
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL); /* Waits for the child to conclude */
	}
}
