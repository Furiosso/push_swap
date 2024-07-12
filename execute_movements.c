/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:22:02 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 12:37:06 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_up(t_stack **stack_a, t_stack **stack_b, t_params *params);
static void	move_down(t_stack **stack_a, t_stack **stack_b, t_params *params);
static void	alt_au_bd(t_stack **stack_a, t_stack **stack_b, t_params *params);
static void	alt_bu_ad(t_stack **stack_a, t_stack **stack_b, t_params *params);

void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	if (params->move == 1)
		move_up(stack_a, stack_b, params);
	if (params->move == 2)
		move_down(stack_a, stack_b, params);
	if (params->move == 3)
		alt_au_bd(stack_a, stack_b, params);
	if (params->move == 4)
		alt_bu_ad(stack_a, stack_b, params);
	push_stack("pb", stack_b, stack_a);
}

static void	move_up(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos
		|| (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos
			&& (*stack_b)->position != params->target)
			rr(stack_a, stack_b);
		if ((*stack_a)->position != params->pos
			&& (*stack_b)->position == params->target)
			rotate("ra", stack_a);
		if ((*stack_a)->position == params->pos
			&& (*stack_b)->position != params->target)
			rotate("rb", stack_b);
	}
}

static void	move_down(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos
		|| (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos
			&& (*stack_b)->position != params->target)
			rrr(stack_a, stack_b);
		if ((*stack_a)->position != params->pos
			&& (*stack_b)->position == params->target)
			reverse_rotate("rra", stack_a);
		if ((*stack_a)->position == params->pos
			&& (*stack_b)->position != params->target)
			reverse_rotate("rrb", stack_b);
	}
}

static void	alt_au_bd(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos
		|| (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos)
			rotate("ra", stack_a);
		if ((*stack_b)->position != params->target)
			reverse_rotate("rrb", stack_b);
	}
}

static void	alt_bu_ad(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	while ((*stack_a)->position != params->pos
		|| (*stack_b)->position != params->target)
	{
		if ((*stack_a)->position != params->pos)
			reverse_rotate("rra", stack_a);
		if ((*stack_b)->position != params->target)
			rotate("rb", stack_b);
	}
}
