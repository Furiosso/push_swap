#include "push_swap.h"

void	move_up(t_stack **stack_a, t_stack **stack_b, t_params *params);
void	move_down(t_stack **stack_a, t_stack **stack_b, t_params *params);
void	move_aup_bdown(t_stack **stack_a, t_stack **stack_b, t_params *params);
void	move_bup_adown(t_stack **stack_a, t_stack **stack_b, t_params *params);

void	execute_movements(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	if (params->move == 1)
		move_up(stack_a, stack_b, params);
	if (params->move == 2)
		move_down(stack_a, stack_b, params);
	if (params->move == 3)
		move_aup_bdown(stack_a, stack_b, params);
	if (params->move == 4)
		move_bup_adown(stack_a, stack_b, params);
	push_stack("pb", stack_b, stack_a);
}

void	move_up(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos || (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos && (*stack_b)->position != params->target)
			rr(stack_a, stack_b);
		if ((*stack_a)->position != params->pos && (*stack_b)->position == params->target)
			rotate("ra", stack_a);
		if((*stack_a)->position == params->pos && (*stack_b)->position != params->target)
			rotate("rb", stack_b);
	}
}

void	move_down(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos || (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos && (*stack_b)->position != params->target)
			rrr(stack_a, stack_b);
		if ((*stack_a)->position != params->pos && (*stack_b)->position == params->target)
			reverse_rotate("rra", stack_a);
		if((*stack_a)->position == params->pos && (*stack_b)->position != params->target)
			reverse_rotate("rrb", stack_b);
	}
}

void	move_aup_bdown(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos || (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos)
			rotate("ra", stack_a);
		if ((*stack_b)->position != params->target)
			reverse_rotate("rrb", stack_b);
	}
}

void	move_bup_adown(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos || (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos)
			reverse_rotate("rra", stack_a);
		if ((*stack_b)->position != params->target)
			rotate("rb", stack_b);
	}
}
