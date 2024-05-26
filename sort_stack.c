#include "push_swap.h"

void	sa(char draw, t_stack **stack_a);
void	sb(char draw, t_stack **stack_b);
void	sort_stack(t_stack *stack_a);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_stack));
}

void	sa(char draw, t_stack **stack_a)
{
	int	aux;

	if (*stack_a && (*stack_a)->next)
	{
		aux = (*stack_a)->number;
		(*stack_a)->number = (*stack_a)->next->number;
		(*stack_a)->next->number = aux;
		if (draw)
			write(1, "sa\n", 3);
	}
}

void	sb(char draw, t_stack **stack_b)
{
	int	aux;

	if (*stack_b && (*stack_b)->next)
	{
		aux = (*stack_b)->number;
		(*stack_b)->number = (*stack_b)->next->number;
		(*stack_b)->next->number = aux;
		if (draw)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(0, stack_a);
	sb(0, stack_b);
	write(1, "ss\n", 3);
}
