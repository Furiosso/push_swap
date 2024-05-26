#include "push_swap.h"

int	main(int len, const char **argv)
{
	t_stack	*stack_a;

	if (len < 2)
		return (0);
	stack_a = check_validity(len, argv);
	if (!stack_a)
		return (0);
	sort_stack(stack_a);
	clean(stack_a);
}
