#include "push_swap.h"

void	reverse_rotate(char *str, t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->prev;
	if (str)
	{
		//ft_printf("%s\n", str);
		write(1, str, 3);
		write(1, "\n", 1);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(NULL, stack_a);
	reverse_rotate(NULL, stack_b);
	//ft_printf("rrr\n");
	write(1, "rrr\n", 4);
}
