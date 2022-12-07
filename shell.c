#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
    char *path = NULL, *buff = NULL, *fullpathbuffer = NULL;
    int parsedStrLen;
    char **parsedStr, *copy = NULL;
    ssize_t readcount = 0;
    size_t n = 0;

    /**getenv is to give all the path like this*/
    path = _getenv("PATH");
    if (path == NULL)
        return (-1);
    while (1)
    {
        parsedStr = NULL;
        buff = NULL;
        prompt();

        readcount = getline(&buff, &n, stdin);
        if (readcount == -1)
        {
            free(buff);
            exit(0);
        }
        parsedStrLen = numOfWords(buff);
        if (parsedStrLen > 0)
        {
            parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
            if (parsedStr == NULL)
            {
                fprintf(stderr, "malloc failed");
                exit(1);
            }
            parsedStr[parsedStrLen] = NULL;
            parseString(buff, parsedStr);
            fullpathbuffer = allpath(parsedStr, path, copy);
            if (check(parsedStr, buff) != 0)
                continue;
            forkk(parsedStr, buff, fullpathbuffer);
        }
        else
            free(buff);
    }
    return (0);
}