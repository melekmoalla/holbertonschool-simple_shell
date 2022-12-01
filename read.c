#include "simple.h"

char *read_line(void)

{
    int bufsize = 1024;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        free(buffer);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {

        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        if (position >= bufsize)
        {
            bufsize += 1024;
            free(buffer);
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                free(buffer);
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}