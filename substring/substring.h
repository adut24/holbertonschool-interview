#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int is_valid_substring(char const *s, char const **words, int word_len,
					   int nb_words, int start);

#endif /* SUBSTRING_H */
