#include "simple.h"
#include <unistd.h>
/**
 * main - master fonction
 * Return: 0
 */

int main(void)
{
	int status, a, parsedStrLen;
	pid_t id;
	size_t size = 32;
	char buffer[100], *sentence = buffer, **parsedStr;

	while (1)
	{
		if (getline(&sentence, &size, stdin) == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				sentence = NULL;
				free(sentence);
				perror("");
				exit(0);
			}
		}
		else
		{
			parsedStrLen = numOfWords(sentence);
			if (parsedStrLen > 0)
			{
				parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
				if (parsedStr == NULL)
				{
					fprintf(stderr, "malloc failed");
					return (1);
				}
				parsedStr[parsedStrLen] = NULL;
				parseString(sentence, parsedStr);
				id = fork();
				if (strcmp(parsedStr[0], "exit") == 0)
				{
					freeArr(parsedStr);
					exit(0);
				}
				if (id == 0)
				{
					a = exeCommand(parsedStr);
					if (a == 127)
					{
						return (127);
					}
				}
				if (id == -1)
				{
					perror("");
					freeArr(parsedStr);
					return (1);
				}
				else
				{
					wait(&status);
					freeArr(parsedStr);
				}
			}
		}
	}
	return (0);
}
