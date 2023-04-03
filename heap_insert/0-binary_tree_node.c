#include "binary_trees.h"

/**
 * binary_tree_node - insert a node inside a binary tree
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	newNode = malloc(sizeof(binary_tree_t));
	/* If the creation of the new node fail, return NULL */
	if (!newNode)
		return (NULL);
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	/* If the pointer to the parent node is NULL, return the new node */
	newNode->parent = parent;
	return (newNode);
}
