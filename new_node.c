#include "push_swap.h"

t_stack	*new_node(int number)
{
	t_stack *new_node;

	new_node = ft_calloc(sizeof(t_stack), 1);
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}
