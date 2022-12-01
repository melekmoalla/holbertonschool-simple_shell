#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    char *line, **args;
    int wa9if;
    while (1)
    {
        printf("mayouka>>");
        line = read_line();
        args = paress(line);
        wa9if = execute(args);
        if (wa9if == 0)
            break;
        free(line);
        free(args);
    }
    return (EXIT_SUCCESS);
}