#include "simple.h"

/**
 * parseString - fonction taht do pares of a command
 * @parsedStr: char
 * @sentence: char
 */

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
