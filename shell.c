#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
	size_t size = 32;
	int parsedStrLen;
	pid_t id;
	char buffer[32], *sentence = buffer, **parsedStr;
	while (1)
	{
		if (getline(&sentence, &size, stdin) == -1)
		{
			if (feof(stdin))
			{
				freeArr(&sentence);
				exit(EXIT_SUCCESS);
			}
			else
			{
				freeArr(&sentence);
				exit(EXIT_FAILURE);
			}
		}
		parsedStrLen = numOfWords(sentence);
		if (parsedStrLen > 0)
		{
			parsedStr = malloc((parsedStrLen + 1) * sizeof(char *));
			if (parsedStr == NULL)
			{
				fprintf(stderr, "malloc failed");
				freeArr(&sentence);
				exit(1);
			}
			parsedStr[parsedStrLen] = NULL;
			parseString(sentence, parsedStr);
			if (strcmp(parsedStr[0], "exit") == 0)
			{
				freeArr(parsedStr);
				break;
			}
			id = fork();
			if (id < 0)
			{
				printf("ERR");
				free(parsedStr);
				exit(1);
			}
			else if (id == 0)
			{
				exeCommand(parsedStr);
				freeArr(parsedStr);
			}
			else
			{
				wait(NULL);
				freeArr(parsedStr);
			}
		}
	}

	return (0);
}