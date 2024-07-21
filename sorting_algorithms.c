/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:55:11 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/13 15:18:32 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	t_stack	*aux;
	int		max;
	int		i;

	i = 3;
	max = 0;
	aux = *stack;
	while (i--)
	{
		if (aux->position > max)
			max = aux->position;
		aux = aux->next;
	}
	if ((*stack)->position == max)
		rotate("ra", stack);
	else if ((*stack)->next->position == max)
		reverse_rotate("rra", stack);
	if ((*stack)->position > (*stack)->next->position)
		swap("sa", stack);
}

void	sort_3_backwards(t_stack **stack)
{
	t_stack	*aux;
	int		min;
	int		i;

	i = 3;
	min = INT_MAX;
	aux = *stack;
	while (i--)
	{
		if (aux->position < min)
			min = aux->position;
		aux = aux->next;
	}
	if ((*stack)->position == min)
		rotate("rb", stack);
	else if ((*stack)->next->position == min)
		reverse_rotate("rrb", stack);
	if ((*stack)->position < (*stack)->next->position)
		swap("sb", stack);
}
