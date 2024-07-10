#include "push_swap.h"

void	rotate(char *str, t_stack **stack)
{
	if(!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (str)
	{
		//ft_printf("%s\n", str);
		write(1, str, 2);
		write(1, "\n", 1);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(NULL, stack_a);
	rotate(NULL, stack_b);
//	ft_printf("rr\n");
	write(1, "rr\n", 3);
}
