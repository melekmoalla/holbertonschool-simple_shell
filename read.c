#include "simple.h"

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
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