#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SENTENCE_LEN 511
#define PATH_MAX 512

void printPrompt();
char *getUserName();
int numOfWords(const char sentence[]);
void parseString(char sentence[], char **parsedStr);
void freeArr(char **parsedStr);
void exeCommand(char **command);
void donePrint(int numOfCommands, int lengthOfCommands);

int main()
{
    char buffer[32];
    pid_t id;
    size_t size = 32;
    char *sentence = buffer;
    char **parsedStr;
    int numOfCommands = 0, lengthOfCommands = 0, parsedStrLen;

    while (1)
    {
        printPrompt();
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
                if (strcmp(parsedStr[0], "done") == 0 && parsedStrLen == 1)
                {
                    donePrint(numOfCommands, lengthOfCommands);
                    freeArr(parsedStr);
                    break;
                }

                id = fork();
                if (id < 0)
                {
                    perror("ERR");
                    freeArr(parsedStr);
                    exit(1);
                }
                else if (id == 0)
                {
                    exeCommand(parsedStr);
                    freeArr(parsedStr);
                }
                else
                {
                    wait(NULL);
                    freeArr(parsedStr);
                }
            }
        }
    }
    return 0;
}

void printPrompt()
{
    char *userName = getUserName();
    char currentDir[PATH_MAX];

    getcwd(currentDir, sizeof(currentDir));
    printf("%s@%s>", userName, currentDir);
}

char *getUserName()
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw)
        return pw->pw_name;
    else
    {
        return NULL;
    }
}

int numOfWords(const char sentence[])
{
    int i = 0, wordCounter = 0;
    while (sentence[i] != '\n')
    {
        if (sentence[i] != ' ' && (sentence[i + 1] == ' ' || sentence[i + 1] == '\n'))
            wordCounter++;
        i++;
    }
    return wordCounter;
}

/*receives a sentence as a char[] and a char**
 *assign dynamically the sentence words into the char**
 */
void parseString(char sentence[], char **parsedStr)
{
    long unsigned int i;
    char tmpWord[SENTENCE_LEN];
    int tmpIndex = 0, parsedIndex = 0;

    for (i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] != ' ' && sentence[i] != '\n')
        {
            tmpWord[tmpIndex] = sentence[i];
            tmpIndex++;
        }

        else if ((sentence[i] == ' ' || sentence[i] == '\n') && tmpIndex > 0)
        {
            tmpWord[tmpIndex] = '\0';
            parsedStr[parsedIndex] = (char *)malloc((strlen(tmpWord)) + 1);
            if (parsedStr[parsedIndex] == NULL)
            {
                freeArr(parsedStr);
                fprintf(stderr, "malloc failed");
                exit(1);
            }
            strcpy(parsedStr[parsedIndex], tmpWord);
            parsedIndex++;
            tmpIndex = 0;
        }
    }
}

void freeArr(char **parsedStr)
{
    int i = 0;
    while (parsedStr[i])
        free(parsedStr[i++]);
    free(parsedStr);
}

void exeCommand(char **command)
{
    if (strcmp(command[0], "cd") == 0)
    {
        printf("command not supported (YET)\n");
        freeArr(command);
        exit(0);
    }
    else if (execvp(command[0], command) != -1)
    {
        freeArr(command);
        exit(0);
    }
    else
    {
        perror("command not found");
        freeArr(command);
        exit(1);
    }
}

void donePrint(int numOfCommands, int lengthOfCommands)
{
    printf("Num of commands: %d\n", numOfCommands);
    printf("Total length of all commands: %d\n", lengthOfCommands);
    printf("Average length of all commands: %f\n", (double)(lengthOfCommands) / numOfCommands);
    printf("See you Next time !\n");
}