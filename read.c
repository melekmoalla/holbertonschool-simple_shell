#include "simple.h"

char *read_line(void)
{
    char buffer[32];
    char *line = buffer;
    size_t bufsize = 32;
    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("lsh: getline\n");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}