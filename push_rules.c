#include "push_swap.h"

static void	first_node(t_stack **stack, t_stack *node);
static void	insert_node(t_stack **stack, t_stack *node);

void	push_stack(char *str, t_stack **stack, t_stack **node)
{
	t_stack	*aux;
	int	size;

	if (!*node)
		return ;
	size = list_size(*node);
	aux = *node;
	if (size == 1)
		*node = NULL;
	else
	{
		(*node)->prev->next = (*node)->next;
		(*node)->next->prev = (*node)->prev;
		*node = (*node)->next;
	}
	if (!*stack)
		first_node(stack, aux);
	else 
		insert_node(stack, aux);
	//ft_printf("%s\n", str);
	write(1, str, 2);
	write(1, "\n", 1);
}

static void	first_node(t_stack **stack, t_stack *node)
{
	*stack = node;
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
}

static void	insert_node(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	node->prev = (*stack)->prev;
	node->prev->next = node;
	(*stack)->prev = node;
	*stack = node;
}
