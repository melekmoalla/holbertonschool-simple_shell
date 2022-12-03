#include "simple.h"

void exeCommand(char **command)
{
    char *envp[] = {(char *)"printenv PATH", 0};
    char cmd[100];

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
    strcpy(cmd, "/bin/bash");
    if (execve(cmd, command, envp))
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