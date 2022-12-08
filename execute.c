#include "simple.h"

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

int forkk(char **parsedStr, char *buffer, char *fullpathbuffer)
{
    int status, z, exitt = 0;
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
        exitt = WEXITSTATUS(status);
    }
    freeArr(parsedStr);
    free(buffer);
    return (exitt);
}