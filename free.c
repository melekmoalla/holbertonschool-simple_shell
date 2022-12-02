#include "simple.h"

void freeArr(char **parsedStr)
{
    int i = 0;
    while (parsedStr[i])
        free(parsedStr[i++]);
    free(parsedStr);
}
