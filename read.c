#include "simple.h"

char *read_line(void)
{
    int size = 1024, pos = 0, c;
    char *buf = malloc(sizeof(char) * size);

    if (!buf)
    {
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        c = getchar();

        if (c == EOF)
        {
            exit(EXIT_SUCCESS);
        }
        else if (c == '\n')
        {
            buf[pos] = '\0';
            return (buf);
        }
        else
        {
            buf[pos] = c;
        }
        pos++;

        if (pos >= size)
        {
            size = 2 * 1024;
            buf = realloc(buf, size);
        }
    }
}