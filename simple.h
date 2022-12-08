#ifndef INV_TREE_H
#define INV_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int main(void);
int numOfWords(const char sentence[]);
void parseString(char sentence[], char **parsedStr);
char *allpath(char **parsedStr, char *PATH, char *copy);
int _pathstrcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **av, char *tok);
int execve_env(char *buf, const char *file, char *const argv[]);
int forkk(char **parsedStr, char *buffer, char *fullpathbuffer);
int check(char **parsedStr, char *buff);

void freeArr(char **parsedStr);
char *_getenv(const char *name);
int _env(void);
char *_memset(char *s, char b, unsigned int n);
char *_strdup(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif