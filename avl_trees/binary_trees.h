#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <limits.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *);

int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int get_max_value(const binary_tree_t *tree);
int get_min_value(const binary_tree_t *tree);
int get_binary_tree_height(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
