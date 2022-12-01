#include "simple.h"

#define TOK 64
#define TOK_DELIM " \t\r\n\a"

char **paress(char *line)
{
    int size = 64, pos = 0;
    char *token;
    char **tokens = malloc(size * sizeof(char *));

    if (!tokens)
    {
        fprintf(stderr, "hsh: allocation erreor\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[pos] = token;
        pos++;

        if (pos >= size)
        {
            size += 64;
            tokens = realloc(tokens, size * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "hsh: allocation erreor\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[pos] = NULL;
    return (tokens);
}