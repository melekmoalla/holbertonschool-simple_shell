#ifndef INV_TREE_H
#define INV_TREE_H
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <paths.h>
#define SENTENCE_LEN 511
#define PATH_MAX 512
int main(void);
int numOfWords(const char sentence[]);
void parseString(char sentence[], char **parsedStr);
void freeArr(char **parsedStr);
int exeCommand(char **command);
#endif