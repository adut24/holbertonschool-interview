#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>

void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void copy_array(int *src, int *dest, size_t size);
void sort(int *array, size_t size, int exp);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
