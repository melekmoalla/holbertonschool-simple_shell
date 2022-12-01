#ifndef INV_TREE_H
#define INV_TREE_H
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct op
{
    char *opp;
    int (*f)(char **);
} op_t;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv);
char *read_line(void);
char **paress(char *line);
int execute(char **args);
int launch(char **args);
#endif