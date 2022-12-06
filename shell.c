#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
	int status, parsedStrLen;
	pid_t id;
	size_t size = 32;
	char buffer[32], *sentence = buffer, **parsedStr;

	while (1)
	{

		while (1)
		{
			if (getline(&sentence, &size, stdin) == -1)
			{
				if (feof(stdin))
					exit(EXIT_SUCCESS);
				else
				{
					wait(NULL);
					return (0);
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
						a = exeCommand(parsedStr);
						freeArr(parsedStr);
						if (a == 1)
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
	}
	return (0);
}