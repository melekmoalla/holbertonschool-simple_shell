#include "simple.h"

/**
 * parseString - fonction that do pares a the line
 * @sentence: line that will pares it.
 * @parsedStr: the variable that will update the malloc
 */

void parseString(char sentence[], char **parsedStr)
{
	unsigned long int i;
	char tmpWord[SENTENCE_LEN];
	int tmpIndex = 0, parsedIndex = 0;

	for (i = 0; i < strlen(sentence); i++)
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
