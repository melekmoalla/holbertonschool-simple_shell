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
			exit(2);
		}
		else
		{
			wait(NULL);
			exit(2);
		}
	}
	exit(0);
}
