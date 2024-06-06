#include "push_swap.h"
#include <stdio.h>

int	main(int len, const char **argv)
{
	t_stack	*stack_a;
	//t_stack	*aux;

	if (len < 2)
		return (0);
	stack_a = check_validity(len, argv);
	if (!stack_a)
		return (0);
	sort_stack(&stack_a);
	/*aux = stack_a;
	while (aux)
	{
		printf(" %d |", aux->number);
		aux = aux->next;
	}
	printf("\n");*/
	clean(stack_a);
}
