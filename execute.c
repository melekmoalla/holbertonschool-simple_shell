#include "simple.h"

/**
 * exeCommand - foknction that do execute the command
 * @command: the line of the command
 */

void exeCommand(char **command)
{

	if (strcmp(command[0], "cd") == 0)
	{
		if (command[1] == NULL)
		{
			fprintf(stderr, "hsh: expected argument to \"cd\" \n");
			freeArr(command);
			exit(0);
		}
		else
		{
			if (chdir(command[1]) != 0)
			{
				printf("hsh: cd");
			}
			freeArr(command);
			exit(0);
		}
	}

	if (execvekernel(*command, command[0], command))
	{
		freeArr(command);
		exit(0);
	}
	else
	{
		perror("command not found");
		freeArr(command);
		exit(1);
	}
}
