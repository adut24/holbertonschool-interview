#include "substring.h"

/**
 * is_valid_substring - Checks if the substring is valid
 *
 * @s: The string to search
 * @words: The array of words all substrings
 * @word_len: The length of each word
 * @nb_words: The number of elements in the array words
 * @start: The starting index of the substring
 *
 * Return: 1 if the substring is valid, otherwise 0
 */
int is_valid_substring(char const *s, char const **words, int word_len,
					   int nb_words, int start)
{
	int index, i, j;
	int *word_count = calloc(nb_words, sizeof(int));
	char *word;

	for (i = 0; i < nb_words; i++)
	{
		index = start + i * word_len;
		*word = strdup(s + index);

		for (j = 0; j < nb_words; j++)
		{
			if (word_count[j] == 0 && strncmp(word, words[j], word_len) == 0)
			{
				word_count[j] = 1;
				break;
			}
		}
	}

	for (i = 0; i < nb_words; i++)
	{
		if (word_count[i] == 0)
		{
			free(word_count);
			return 0;
		}
	}

	free(word_count);
	return 1;
}

/**
 * find_substring - Finds if the string contains the substring
 *
 * @s: The string to search
 * @words: The array of words all substrings
 * @nb_words: The number of elements in the array words
 * @n: The address at which to store the number of elements in the returned
 *
 * Return: The array of indices at which a substring was found, or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]), s_len = strlen(s);
	int substr_len = word_len * nb_words;
	int count = 0, i;
	int *indices = malloc(s_len * sizeof(int));

	for (i = 0; i <= s_len - substr_len; i++)
	{
		if (is_valid_substring(s, words, word_len, nb_words, i))
			indices[count++] = i;
	}

	*n = count;
	if (count == 0)
	{
		free(indices);
		return NULL;
	}

	indices = realloc(indices, count * sizeof(int));
	return indices;
}
