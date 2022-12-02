#include "simple.h"

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