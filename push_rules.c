#include "push_swap.h"

void	push_stack(char *str, t_stack **stack, t_stack **node)
{
	t_stack	*aux;

	if (!*node)
		return ;
	if (!*stack)
	{
		*stack = *node;
		*node = (*node)->next;
		(*stack)->next = NULL;
	}
	else 
	{
		aux = *node;
		*node = aux->next;
		aux->next = *stack;
		*stack = aux;
	}
	//ft_printf("%s\n", str);
	write(1, str, 2);
	write(1, "\n", 1);
}
/*
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (!*stack_a)
		return ;
	aux = *stack_a;
	*stack_a = aux->next;
	aux->next = *stack_b;
	*stack_b = aux;
	write(1, "pb\n", 3);
}*/
