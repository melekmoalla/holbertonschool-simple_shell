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
	char buffer[32], *sentence = buffer, **parsedStr;

	while (getline(&sentence, &size, stdin) != -1)
	{
		parsedStrLen = numOfWords(sentence);
		if (parsedStrLen > 0)
		{
			parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
			if (parsedStr == NULL)
			{
				free(parsedStr);
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
				id = 0;
			}
			freeArr(parsedStr);
			id = 0;
			parsedStrLen = 0;
		}
	}
	return (EXIT_SUCCESS);
}