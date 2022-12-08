#include "simple.h"

/**
 * numOfWords - fonction dispaly the number of the word in the line
 * @sentence: char
 * Return: wordCounter
 */
int numOfWords(const char sentence[])
{
	int i = 0, wordCounter = 0;

	while (sentence[i] != '\n')
	{
		if (sentence[i] != ' ' && (sentence[i + 1] == ' ' ||
								   sentence[i + 1] == '\n'))
			wordCounter++;
		i++;
	}
	return (wordCounter);
}

/**
 *_concat - fonction taht concat two sting bettwen /
 * @tmp: char
 * @av: char
 * @tok: char
 * Return: tmp
 */
char *_concat(char *tmp, char **av, char *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tok) + _strlen(av[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
