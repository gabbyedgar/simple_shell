#include "main.h"

#include "shell.h"

/**
 * _strcat - concatenate two strings.
 * @dest: destination string.
 * @src: source string.
 * Return: pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*temp)
		temp++;

	while (*src)
		*temp++ = *src++;

	*temp = '\0';

	return dest;
}

/**
 * _strcpy - copy a string.
 * @dest: destination string.
 * @src: source string.
 * Return: pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while ((*temp++ = *src++))
		;

	return dest;
}

/**
 * _strcmp - compare two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if the strings are equal, a positive value if s1 is greater,
 *         and a negative value if s2 is greater.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strchr - locate a character in a string.
 * @s: string.
 * @c: character.
 * Return: pointer to the first occurrence of the character c,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return s;
		s++;
	}

	if (*s == c)
		return s;

	return NULL;
}
