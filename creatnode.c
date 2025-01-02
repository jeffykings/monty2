#include "monty.h"

/**
 * crt_Node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *crt_Node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errorr(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
