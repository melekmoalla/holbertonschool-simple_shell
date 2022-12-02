#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple.h"

int main()
{
    int status;
    char buffer[32];
    pid_t id;
    size_t size = 32;
    char *sentence = buffer;
    char **parsedStr;
    int numOfCommands = 0, lengthOfCommands = 0, parsedStrLen;

    while (1)
    {

        if (getline(&sentence, &size, stdin) != -1)
        {
            parsedStrLen = numOfWords(sentence);
            lengthOfCommands += (int)(strlen(sentence));
            numOfCommands++;
            if (parsedStrLen > 0)
            {
                parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
                if (parsedStr == NULL)
                {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }
                parsedStr[parsedStrLen] = NULL;
                parseString(sentence, parsedStr);

                id = fork();
                if (id < 0)
                {
                    perror("ERR");
                    freeArr(parsedStr);
                    exit(1);
                }
                else if (id == 0)
                {
                    if (strcmp(parsedStr[0], "exit") == 0)
                    {

                        break;
                    }
                    exeCommand(parsedStr);
                    freeArr(parsedStr);
                }
                else
                {
                    while (!WIFEXITED(status) && !WIFSIGNALED(status))
                    {
                        waitpid(id, &status, WUNTRACED);
                    }
                    freeArr(parsedStr);
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}