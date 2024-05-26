#include "push_swap.h"

void	ra(char draw, t_stack **stack_a)
{
	t_stack	*aux1;
	t_stack *aux2;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	aux1 = *stack_a;
	*stack_a = (*stack_a)->next;
	aux2 = *stack_a;
	while (aux2->next)
		aux2 = aux2->next;
	aux2->next = aux1;
	aux1->next = NULL;
	if (draw)
		write(1, "ra\n", 3);
}

void	rb(char draw, t_stack **stack_b)
{
	t_stack	*aux1;
	t_stack *aux2;

	if(!*stack_b || !(*stack_b)->next)
		return ;
	aux1 = *stack_b;
	*stack_b = (*stack_b)->next;
	aux2 = *stack_b;
	while (aux2->next)
		aux2 = aux2->next;
	aux2->next = aux1;
	aux1->next = NULL;
	if (draw)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(0, stack_a);
	rb(0, stack_b);
	write(1, "rr\n", 3);
}

