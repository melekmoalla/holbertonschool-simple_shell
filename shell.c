#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
	int parsedStrLen;
	pid_t id;
	size_t size = 32;
	int a = 0;
	char buffer[32], *sentence = buffer, **parsedStr;
	while (1)
	{
		a = getline(&sentence, &size, stdin);
		if (a == EOF)
		{
			exit(127);
		}
		else if (*buffer == '\n')
		{
			freeArr(&sentence);
			exit(127);
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
					return (0);
				}
				else if (id < 0)
				{
					perror("ERR");
					freeArr(parsedStr);
					exit(1);
				}
				else if (id == 0)
				{
					exeCommand(parsedStr);
				}
				else
				{
					wait(NULL);
				}
				freeArr(parsedStr);
			}
		}
	}
	return (EXIT_SUCCESS);
}