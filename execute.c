#include "simple.h"

void exeCommand(char **command)
{
    char hack[200];

    if (strcmp(command[0], "cd") == 0)
    {
        if (command[1] == NULL)
        {
            fprintf(stderr, "hsh: expected argument to \"cd\" \n");
            freeArr(command);
            exit(0);
        }
        else
        {
            if (chdir(command[1]) != 0)
            {
                printf("hsh: cd");
            }
            freeArr(command);
            exit(0);
        }
    }
    strcpy(hack, "/bin/sh");
    if (execve(hack, command, NULL))
    {
        freeArr(command);
        exit(EXIT_FAILURE);
    }
    else
    {
        perror("command not found");
        freeArr(command);
        exit(1);
    }
}