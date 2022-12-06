#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
	int parsedStrLen;
	pid_t id;
	size_t size = 1024;
	char buffer[1024], *sentence = buffer, **parsedStr;

	while (1)
	{
		if (getline(&sentence, &size, stdin) != -1)
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
		else
		{
			{
				freeArr(&sentence);
				exit(127);
			}
		}
	}
	exit(0);
}