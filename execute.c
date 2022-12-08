#include "simple.h"

/**
 *check - fonction taht check if we write exit of no
 * @parsedStr: char
 * @buff: char
 * Return: 0
 */
int check(char **parsedStr, char *buff)
{

	if (_strcmp(parsedStr[0], "exit") == 0)
	{
		freeArr(parsedStr);
		free(buff);
		exit(0);
	}
	return (0);
}

/**
 * forkk -fonction that do fork and execute
 * @parsedStr: char
 * @buffer: char
 * @fullpathbuffer: char
 * Return: 0 or 127
 */
int forkk(char **parsedStr, char *buffer, char *fullpathbuffer)
{
	int status, z;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("eroe");
		exit(1);
	}
	if (pid == 0)
	{
		z = execve(fullpathbuffer, parsedStr, NULL);
		if (z == -1)
		{

			perror("error");
			freeArr(parsedStr);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		WEXITSTATUS(status);
	}
	freeArr(parsedStr);
	free(buffer);
	return (0);
}
