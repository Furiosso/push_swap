#include "push_swap.h"

void	swap(char *str, t_stack **stack)
{
	int	num;
	size_t	pos;

	if (*stack && (*stack)->next)
	{
		num = (*stack)->number;
		pos = (*stack)->position;
		(*stack)->position = (*stack)->next->position;
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->position = pos;
		(*stack)->next->number = num;
		if (str)
		{
			//ft_printf("%s\n", str);
			write(1, str, 2);
			write(1, "\n", 1);
		}
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(NULL, stack_a);
	swap(NULL, stack_b);
	//ft_printf("ss\n");
	write(1, "ss\n", 3);
}
