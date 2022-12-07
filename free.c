#include "simple.h"

/**
 * freeArr - foncton that free a sting
 * @parsedStr: string that you want to delet
 */

void freeArr(char **parsedStr)
{
	int i = 0;

	while (parsedStr[i])
		free(parsedStr[i++]);
	free(parsedStr);
	
}
