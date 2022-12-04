#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple.h"

int main()
{

    char buffer[32];
    size_t size = 32;
    char *sentence = buffer;
    char **parsedStr;
    int parsedStrLen;
    int a = 0;
    pid_t id;
    int status;
    while (1)
    {

        if (getline(&sentence, &size, stdin) == -1)
        {
            if (feof(stdin))
            {
                exit(EXIT_SUCCESS);
            }
            {
                wait(&status);
                return (WEXITSTATUS(status));
            }
        }
        else
        {
            parsedStrLen = numOfWords(sentence);
            if (parsedStrLen > 0)
            {
                parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
                if (parsedStr == NULL)
                {
                    fprintf(stderr, "malloc failed");
                    return (1);
                }
                parsedStr[parsedStrLen] = NULL;
                parseString(sentence, parsedStr);
                if (a == 0)
                {

                    id = fork();
                    if (strcmp(parsedStr[0], "exit") == 0)
                    {
                        freeArr(parsedStr);
                        exit(0);
                        break;
                    }

                    if (id == 0)
                    {
                        exeCommand(parsedStr);
                        freeArr(parsedStr);
                    }
                    else if (id < 0)
                    {
                        perror("ERR");
                        freeArr(parsedStr);
                    }
                    else
                    {
                        wait(&status);
                        freeArr(parsedStr);
                        return (WEXITSTATUS(status));
                    }
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}