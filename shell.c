#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
	int parsedStrLen, a;
	pid_t id;
	char buffer[32], *sentence = buffer, **parsedStr;

	while (1)
	{
		if (check(sentence) == 2)
		{
			break;
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
					exit(1);
				}
				parsedStr[parsedStrLen] = NULL;
				parseString(sentence, parsedStr);
				id = fork();
				if (strcmp(parsedStr[0], "exit") == 0)
				{
					exit(0);
				}
				else if (id < 0)
				{
					perror("ERR");
					freeArr(parsedStr);
					exit(1);
				}
				else if (id == 0)
				{
					a = exeCommand(parsedStr);
					freeArr(parsedStr);
				}
				else
				{
					wait(NULL);
					freeArr(parsedStr);
				}
				if (a == 1)
				{
					exit(127);
				}
			}
		}
	}
	exit(0);
}
