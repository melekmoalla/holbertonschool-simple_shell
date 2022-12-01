#include "simple.h"

#define TOK 64
#define TOK_DELIM " \t\r\n\a"

char **paress(char *line)
{
    int size = 64, pos = 0;
    char *token, **token_sajil;
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
            size = 2 * 64;
            token_sajil = tokens;
            tokens = realloc(tokens, size * sizeof(char *));
            if (!tokens)
            {
                free(token_sajil);
                fprintf(stderr, "hsh: allocation erreor\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[pos] = NULL;
    return (tokens);
}