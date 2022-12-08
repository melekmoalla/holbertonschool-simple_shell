#include "simple.h"
/**
 * main - master fonction
 * Return: 0
 **/
int main(void)
{
	char *path = NULL, *buff = NULL, *fullpath = NULL, **parsedStr, *copy = NULL;
	int parsedStrLen;
	ssize_t readcount = 0;
	size_t n = 0;

	signal(SIGINT, SIG_IGN);
	/**getenv is to give all the path like this*/
	path = _getenv("PATH");
	if (path == NULL)
		return (-1);
	while (1)
	{
		parsedStr = NULL;
		readcount = getline(&buff, &n, stdin);
		if (readcount == -1)
		{free(buff);
			exit(0); }
		parsedStrLen = numOfWords(buff);
		if (parsedStrLen > 0)
		{
			parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
			if (parsedStr == NULL)
			{fprintf(stderr, "malloc failed");
				exit(1); }
			parsedStr[parsedStrLen] = NULL;
			parseString(buff, parsedStr);
			if (_strcmp(parsedStr[0], "env") == 0)
			{ execvp(parsedStr[0],parsedStr);
				freeArr(parsedStr);
				free(buff);
				continue; }
			fullpath = allpath(parsedStr, path, copy);
			if (check(parsedStr, buff) != 0)
				continue;
			forkk(parsedStr, buff, fullpath); }
		else
			free(buff); }
	return (0);
}
