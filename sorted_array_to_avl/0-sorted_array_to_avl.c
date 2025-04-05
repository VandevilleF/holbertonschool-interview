#include "binary_trees.h"

/**
 * create_node - Creates a new AVL tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	/*Initialize the node fields*/
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * avl_build_tree - Recursively builds a balanced AVL tree
 * @array: Sorted array of integers
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array
 * @parent: Pointer to the parent node of the current subtree
 * Return: Pointer to the root node of this subtree
 */
avl_t *avl_build_tree(int *array, int start, int end, avl_t *parent)
{
	if (start > end)
		return (NULL);

	/*Get the middle index of the current sub-array*/
	int mid = (start + end) / 2;
	avl_t *root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);

	/*Recursively build subtree using half of the array*/
	root->left = avl_build_tree(array, start, mid - 1, root);
	root->right = avl_build_tree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	/*Start building the tree from the full array, root has no parent (NULL)*/
	return (avl_build_tree(array, 0, (int)size - 1, NULL));
}
