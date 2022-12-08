#include "simple.h"

/**
 * allpath - give the true path
 * @parsedStr: char
 * @PATH: char
 * @copy: char
 * Return:path
 */
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

/**
 * _getenv - gets PATH member from environ
 * @name: pointer to PATH string
 * Return: pointer to PATH member string or NULL if not found
 */
char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = _pathstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * _pathstrcmp - fonction taht do comparison bitwen to patgh
 * @s1: const char
 * @s2: const char
 * Return: 0 or -1
 */
int _pathstrcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * _env - dispaly envirment variable
 * @argc: int
 * @argv: char
 * @envp: char
 * Return: 0 or -1
 */
int _env(__attribute__((unused)) int argc,
		 __attribute__((unused)) char *argv[],
		 char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
	return (0);
}
