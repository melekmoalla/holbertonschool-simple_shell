#include "simple.h"

/**
 * check - fonction that do pares a the line
 * @sentence: line that will pares it.
 * Return: 0
 */

int check(char *sentence)
{
	size_t size = 32;

	if (getline(&sentence, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			return (2);
		}
		else
		{
			wait(NULL);
			return (2);
		}
	}
	return (0);
}
