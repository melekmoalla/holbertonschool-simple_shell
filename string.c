#include "simple.h"

/**
 * _memset - fonction taht do comparison bitwen to patgh
 * @s: char
 * @b: char
 * @n: unsigned int n
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _strdup - fonction taht do comparison bitwen to patgh
 * @str: char
 * Return: dest_str
 */
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

/**
 * _strcmp - fonction taht do comparison bettwen two string
 * @s1: const char
 * @s2: const char
 * Return: 0 or s1-s2
 */
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

/**
 * _strcat - fonction that do concatenation
 * @dest: const char
 * @src: const char
 * Return: dest
 */
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

/**
 * _strlen - fonction taht do comparison bitwen to patgh
 * @s: char
 * Return: i
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
