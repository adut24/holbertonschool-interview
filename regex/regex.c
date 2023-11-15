#include "regex.h"
#include <stdio.h>

/**
 * regex_match - Checks if the string is matching the regex pattern
 *
 * @str: string to check
 * @pattern: regular expression
 *
 * Return: 1 if it matches, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*(pattern + 1) == '*')
	{
		while (*str != '\0' && (*str == *pattern || *pattern == '.'))
		{
			if (regex_match(str, pattern + 2))
				return (1);
			str++;
		}
		return (regex_match(str, pattern + 2));
	}

	if (*str != '\0' && (*str == *pattern || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
