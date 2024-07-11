#include "push_swap.h"
#include <stdio.h>

void		sort_stack(t_stack **stack_a);
static void	my_sort(t_stack **stack_a, t_stack **stack_b, int *size);
static void	sort_max(t_stack **stack_a, t_stack **stack_b, int size);
static void	choose_path(t_stack **stack_a, t_stack **stack_b, t_stack *max, int size);
static void	move_to_a(t_stack **stack_a, t_stack **stack_b);

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int	size[3];

	stack_b = NULL;
	size[0] = list_size(*stack_a);
	size[1] = 0;
	size[2] = size[0];
	if (check_order(stack_a, &stack_b, size))
		return ;
	if (size[0] == 3)
		sort_3(stack_a);
	if (size[0] > 3 && size[0] < 6)
		sort_5(stack_a, &stack_b, size[0]);
	if (size[0] > 5)
		my_sort(stack_a, &stack_b, size);
}

void	my_sort(t_stack **stack_a, t_stack **stack_b, int *size)
{
	t_params	*params;

	params = ft_calloc(sizeof(t_params), 1);
	if (!params)
		exit(5) ;
	push_stack("pb", stack_b, stack_a);
	push_stack("pb", stack_b, stack_a);
	push_stack("pb", stack_b, stack_a);
	sort_3_backwards(stack_b);
	size[0] -= 3;
	size[1] = 3;
	while (!check_order(stack_a, stack_b, size) && size[0] > 3)
	{
		set_targets(*stack_a, *stack_b);
		find_the_way(*stack_a, *stack_b, &params);
		execute_movements(stack_a, stack_b, params);
		size[0]--;
		size[1]++;
	}
	if (size[0] == 3)
		sort_3(stack_a);
	sort_max(stack_a, stack_b, size[2]);
	move_to_a(stack_a, stack_b);
	free(params);
}

static void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b || (*stack_a)->position != 1)
	{
		while ((*stack_a)->prev->position == (*stack_a)->position - 1)
			reverse_rotate("rra", stack_a);
		if (*stack_b)
			push_stack("pa", stack_a, stack_b);
	}
}

static void	sort_max(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max;
	t_stack	*aux;
	int	pos;

	max = INT_MIN;
	pos = (*stack_b)->position;
	aux = *stack_b;
	while ((*stack_b)->position != pos || ((*stack_b)->position == pos && !(*stack_b)->flag))
	{
		if ((*stack_b)->position > max)
		{
			max = (*stack_b)->position;
			aux = *stack_b;
		}
		(*stack_b)->flag = 1;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->flag = 0;
	choose_path(stack_a, stack_b, aux, size);
}

static void	choose_path(t_stack **stack_a, t_stack **stack_b, t_stack *max, int size)
{
	char	flag;

	flag = 0;
	if (max->reverse_stack_pos > max->stack_pos)
	{
		while (*stack_b != max)
			rotate("rb", stack_b);
	}
	else
	{
		while (*stack_b != max)
		{
			if ((*stack_a)->prev->position == size && (*stack_b)->prev == max)
			{
				rrr(stack_a, stack_b);
				flag = 1;
			}
			else
				reverse_rotate("rrb", stack_b);
		}
	}
	if ((*stack_a)->prev->position == size && !flag && !is_sorted(*stack_a, 0))
		reverse_rotate("rra", stack_a);
}
