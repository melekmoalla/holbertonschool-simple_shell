#include "simple.h"
#include <unistd.h>
/**
 * exeCommand - foknction that do execute the command
 * @command: the line of the command.
 */

int exeCommand(char **command)
{
	char buf[PATH_MAX];

	if (strcmp(command[0], "cd") == 0)
	{
		if (command[1] == NULL)
		{
			fprintf(stderr, "hsh: expected argument to \"cd\" \n");
			freeArr(command);
			return (0);
		}
		else
		{
			if (chdir(command[1]) != 0)
			{
				printf("hsh: cd");
				freeArr(command);
				return (0);
			}
		}
		return (0);
	}

	if (execvf(buf, command[0], command))
	{
		freeArr(command);
		return (0);
	}
	else
	{
		perror("");
		freeArr(command);
		return (127);
	}
	return (0);
}
