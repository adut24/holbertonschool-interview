#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0, result = 0;

	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	height_l = get_binary_tree_height(tree->left);
	height_r = get_binary_tree_height(tree->right);

	if (height_l > height_r)
		result = height_l - height_r;
	else
		result = height_r - height_l;

	return (result <= 1 ? 1 : 0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && get_max_value(tree->left) > tree->n)
		return (0);

	if (tree->right && get_min_value(tree->right) < tree->n)
		return (0);

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}

/**
 * get_max_value - gets the max value of a binary tree
 *
 * @tree: pointer to root node of the tree to check
 *
 * Return: max value of the tree
*/
int get_max_value(const binary_tree_t *tree)
{
	int max = 0, leftMax = 0, rightMax = 0;

	if (!tree)
		return (0);

	leftMax = get_max_value(tree->left);
	rightMax = get_max_value(tree->right);

	max = leftMax > rightMax ? leftMax : rightMax;

	return (max > tree->n ? max : tree->n);
}

/**
 * get_min_value - gets the min value of a binary tree
 *
 * @tree: pointer to root node of the tree to check
 *
 * Return: min value of the tree
*/
int get_min_value(const binary_tree_t *tree)
{
	int min = 0, leftMin = 0, rightMin = 0;

	if (!tree)
		return (INT_MAX);

	leftMin = get_min_value(tree->left);
	rightMin = get_min_value(tree->right);

	min = leftMin < rightMin ? leftMin : rightMin;

	return (min < tree->n ? min : tree->n);
}

/**
 * get_binary_tree_height - gets the height of a binary tree
 *
 * @tree: pointer to root node of the tree to check
 *
 * Return: height of the tree
*/
int get_binary_tree_height(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = get_binary_tree_height(tree->left) + 1;
	height_r = get_binary_tree_height(tree->right) + 1;

	return (height_l > height_r ? height_l : height_r);
}
