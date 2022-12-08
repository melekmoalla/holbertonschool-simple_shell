#include "simple.h"

/**
 * _getenv - gets PATH member from environ
 * @name: pointer to PATH string
 *
 * Return: pointer to PATH member string or NULL if not found
 */
char *_getenv(const char *name)
{
    int i, result;

    for (i = 0; environ[i]; i++)
    {
        result = _pathstrcmp(name, environ[i]);
        if (result == 0)
        {
            return (environ[i]);
        }
    }
    return (NULL);
}

int _pathstrcmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s2[i] != '='; i++)
    {
        if (s1[i] != s2[i])
            return (-1);
    }
    return (0);
}

int _env(void)
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
        printf("\n%s", environ[i]);
    return (0);
}

char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}

char *_strdup(char *str)
{
    int i;
    char *dest_str = NULL;

    if (str == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        ;
    dest_str = malloc(sizeof(char) * (i + 1));
    if (dest_str == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
    {
        dest_str[i] = str[i];
    }
    dest_str[i] = '\0';
    return (dest_str);
}

int _strcmp(const char *s1, const char *s2)
{
    while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 - *s2);
}

char *_strcat(char *dest, char *src)
{
    int i, j;

    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}

int _strlen(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
        ;
    return (i);
}