#include "simple.h"
#include <unistd.h>
/**
 * main - master fonction
 * Return: 0
 */
int main(void)
{
	int a, parsedStrLen;
	pid_t id;
	size_t size = 32;
	char buffer[100], *sentence = buffer, **parsedStr;
	while (1)
	{
		if (getline(&sentence, &size, stdin) != -1)
		{
			parsedStrLen = numOfWords(sentence);
			if (parsedStrLen > 0)
			{
				parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
				if (parsedStr == NULL)
				{
					fprintf(stderr, "malloc failed");
					exit(1);
				}
				parsedStr[parsedStrLen] = NULL;
				parseString(sentence, parsedStr);
				if (strcmp(parsedStr[0], "exit") == 0)
				{
					free(parsedStr);
					exit(0);
				}
				id = fork();
				if (id < 0)
				{
					perror("");
					freeArr(parsedStr);
					exit(1);
				}
				if (id == 0)
				{
					a = exeCommand(parsedStr);
					if (a == 127)
					{
						return (127);
					}
				}
				else
				{
					wait(NULL);
					freeArr(parsedStr);
				}
			}
		}
	}
	return (0);
}