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

    do
    {
        line = read_line();
        args = paress(line);
        wa9if = execute(args);
        
        free(args);
        free(line);
    } while (wa9if);
    return (EXIT_SUCCESS);
}