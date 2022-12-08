#include "simple.h"

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
char *allpath(char **parsedStr, char *PATH, char *copy)
{
	char *tok = NULL, *path = NULL, *concatstr = NULL;
	static char tmp[200];
	int fullpathflag = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	tok = strtok(copy, ":");
	while (tok != NULL)
	{
		concatstr = _concat(tmp, parsedStr, tok);
		if (stat(concatstr, &h) == 0)
		{
			path = concatstr;
			fullpathflag = 1;
			break;
		}

		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		path = parsedStr[0];
	free(copy);
	return (path);
}
