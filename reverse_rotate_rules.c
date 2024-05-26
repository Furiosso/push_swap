#include "push_swap.h"

void	rra(char draw, t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	aux = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->next && !(*stack_a)->next->next)
				aux2 = *stack_a;
	}
	(*stack_a)->next = aux;
	aux2->next = NULL;
	if (draw)
		write (1, "rra\n", 4);
}

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
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(0, stack_a);
	rrb(0, stack_b);
	write(1, "rrr\n", 4);
}
