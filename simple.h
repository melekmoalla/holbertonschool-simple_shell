#ifndef INV_TREE_H
#define INV_TREE_H
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define SENTENCE_LEN 511
#define PATH_MAX 512

int main(void);
int numOfWords(const char sentence[]);
void parseString(char sentence[], char **parsedStr);
void freeArr(char **parsedStr);
int check(char *sentence);
int exeCommand(char **command);
int execvf(char *buf, const char *file, char *const argv[]);

#endif
