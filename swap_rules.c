#include "push_swap.h"

void	swap(char *str, t_stack **stack)
{
	int	aux;

	if (*stack && (*stack)->next)
	{
		aux = (*stack)->number;
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->number = aux;
		if (str)
		//ft_printf("%s\n", str);
		{
			write(1, str, 2);
			write(1, "\n", 1);
		}
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(NULL, stack_a);
	swap(NULL, stack_b);
	write(1, "ss\n", 3);
}
