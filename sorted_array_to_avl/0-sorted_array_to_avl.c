#include "binary_trees.h"

/**
 * sorted_array_to_avl - Transforms an array into an AVL tree
 * @array: array to transform
 * @size: size of the array
 * Return: NULL or a pointer to the root
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (sorted_array_to_avl_recursive(array, 0, size - 1));
}

/**
 * add_node - Adds a node to the AVL tree
 * @n: number to add to the node
 * Return: NULL or the new node
*/
avl_t *add_node(int n)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = n;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sorted_array_to_avl_recursive - Creates and sorts the AVL tree
 * @array: array to transform
 * @start: starting index
 * @end: Ending index
 * Return: NULL or a pointer to the root
*/
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *root;

	if (start > end)
		return (NULL);

	root = add_node(array[mid]);
	root->left = sorted_array_to_avl_recursive(array, start, mid - 1);
	if (root->left)
		root->left->parent = root;

	root->right = sorted_array_to_avl_recursive(array, mid + 1, end);
	if (root->right)
		root->right->parent = root;

	return (root);
}
