#include <stdio.h>
#include "push_swap.h"

void	push_swap(int argc, const char **argv);

int	main(int argc, const char **argv)
{
	push_swap(argc, argv);
}

void	push_swap(int len, const char **argv)
{
	t_stack	*stack_a;
	int	cont;

	if (len < 2)
		return ;
	stack_a = check_validity(len, argv);
	if (!stack_a)
		return ;
	cont = 0;
	while (stack_a)
	{
		printf("Stack[%d]: %d ", cont, stack_a->number);
		stack_a = stack_a->next;
		cont++;
	}
	clean(stack_a);
}
