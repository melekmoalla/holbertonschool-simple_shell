#include "simple.h"
/**
 * prompt - writes a prompt
 *
 * Return: 0 on sucess
 */
int prompt(void)
{

	printf("$");
	return (0);
}

/**
 * _fullpathbuffer - finds the string to call execve on
 * @av: pointer to array of user strings
 * @PATH: pointer to PATH string
 * @copy: pointer to copy of PATH string
 *
 * Return: a pointer to string to call execve on
 */
char *allpath(char **av, char *PATH, char *copy)
{
	char *tok = NULL, *fullpathbuffer = NULL, *concatstr = NULL;
	static char tmp[256];
	int fullpathflag = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concat(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			fullpathbuffer = concatstr;
			fullpathflag = 1;
			break;
		}

		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		fullpathbuffer = av[0];
	free(copy);
	return (fullpathbuffer);
}

void parseString(char sentence[], char **parsedStr)
{
	char tmpWord[200];
	int tmpIndex = 0, parsedIndex = 0;
	int i;
	for (i = 0; i < _strlen(sentence); i++)
	{
		if (sentence[i] != ' ' && sentence[i] != '\n')
		{
			tmpWord[tmpIndex] = sentence[i];
			tmpIndex++;
		}

		else if ((sentence[i] == ' ' || sentence[i] == '\n') && tmpIndex > 0)
		{
			tmpWord[tmpIndex] = '\0';
			parsedStr[parsedIndex] = (char *)malloc((strlen(tmpWord)) + 1);
			if (parsedStr[parsedIndex] == NULL)
			{
				freeArr(parsedStr);
				fprintf(stderr, "malloc failed");
				exit(1);
			}
			strcpy(parsedStr[parsedIndex], tmpWord);
			parsedIndex++;
			tmpIndex = 0;
		}
	}
}