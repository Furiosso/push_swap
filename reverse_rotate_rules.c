#include "push_swap.h"

void	reverse_rotate(char *str, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (!*stack || !(*stack)->next)
		return ;
	aux = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		if ((*stack)->next && !(*stack)->next->next)
				aux2 = *stack;
	}
	(*stack)->next = aux;
	aux2->next = NULL;
	if (str)
	//ft_printf("%s\n", str);
	{
		write(1, str, 3);
		write(1, "\n", 1);
	}
}
/*
void	rrb(char draw, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	aux = *stack_b;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->next && !(*stack_b)->next->next)
			aux2 = *stack_b;
	}
	(*stack_b)->next = aux;
	aux2->next = NULL;
	if (draw)
		write (1, "rrb\n", 4);
}*/

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(NULL, stack_a);
	reverse_rotate(NULL, stack_b);
	write(1, "rrr\n", 4);
}
