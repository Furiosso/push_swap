#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (!*stack_b)
		return;
	aux = *stack_b;
	*stack_b = aux->next;
	aux->next = *stack_a;
	*stack_a = aux;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (!*stack_a)
		return;
	aux = *stack_a;
	*stack_a = aux->next;
	aux->next = *stack_b;
	*stack_b = aux;
	write(1, "pb\n", 3);
}
