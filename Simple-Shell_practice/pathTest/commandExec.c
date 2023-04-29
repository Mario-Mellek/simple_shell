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
	if (strchr(args[0], '/') != NULL)
	{
		execAbsolute(args, program_name);
	}
	else
	{
		execPath(args, program_name);
	}
}

