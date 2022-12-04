#ifndef INV_TREE_H
#define INV_TREE_H
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SENTENCE_LEN 511
#define PATH_MAX 512

int main();
int numOfWords(const char sentence[]);
void parseString(char sentence[], char **parsedStr);
void freeArr(char **parsedStr);
void exeCommand(char **command);
int execve_noalloc(char *buf, const char *file, char *const argv[]);

#endif