#include "holberton.h"

/**
 * wildcmp - Compares two strings with one possibly containing wildcards
 *
 * @s1: string one
 * @s2: string two
 *
 * Return: 0 or 1
*/
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
