#include "push_swap.h"

void	rotate(char *str, t_stack **stack)
{
	t_stack	*aux1;
	t_stack *aux2;

	if(!*stack || !(*stack)->next)
		return ;
	aux1 = *stack;
	*stack = (*stack)->next;
	aux2 = *stack;
	while (aux2->next)
		aux2 = aux2->next;
	aux2->next = aux1;
	aux1->next = NULL;
	//ft_printf("%s\n", str);
	if (str)
	{
		write(1, str, 2);
		write(1, "\n", 1);
	}
}
/*
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
}*/

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(NULL, stack_a);
	rotate(NULL, stack_b);
	write(1, "rr\n", 3);
}

