#include "sort.h"

/**
 * radix_sort - sorts an array of integers using the Radix sort algorithm
 * @array: integer array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp = 0, max = 0;

	if (size <= 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * get_max - gets the max value in the array
 * @array: array of int
 * @size: size of the array
 * Return: the max value in the array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * copy_array - copies the array src to dest
 * @src: source array
 * @dest: destination array
 * @size: size of the arrays
 */
void copy_array(int *src, int *dest, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
}

/**
 * sort - sorts the array using LSD radix sort
 * @array: array of int
 * @size: size of the array
 * @exp: power of ten to find the significant digit
 */
void sort(int *array, size_t size, int exp)
{
	int *work_array = NULL;
	int count[10] = {0};
	ssize_t i;

	work_array = malloc(sizeof(int) * size);
	if (!work_array)
		return;

	for (i = 0; i < (ssize_t)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (ssize_t)size - 1; i >= 0; i--)
	{
		work_array[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	copy_array(work_array, array, size);
	free(work_array);
}
