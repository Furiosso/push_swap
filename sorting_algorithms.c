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

static char	look_down(t_stack *stack, int needle);

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

void	sort_5(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min;

	min = 1;
	while (size-- > 3)
	{
		if (look_down(*stack_a, min))
		{
			while ((*stack_a)->position != min)
				rotate("ra", stack_a);
		}
		else
		{
			while ((*stack_a)->position != min)
				reverse_rotate("rra", stack_a);
		}
		push_stack("pb", stack_b, stack_a);
		min++;
	}
	sort_3(stack_a);
	while (*stack_b)
		push_stack("pa", stack_a, stack_b);
}

static char	look_down(t_stack *stack, int needle)
{
	t_stack	*aux;
	int		len1;
	int		len2;

	aux = stack;
	len1 = 0;
	len2 = 0;
	while (aux->position != needle)
	{
		aux = aux->next;
		len1++;
	}
	aux = stack;
	while (aux->position != needle)
	{
		aux = aux->prev;
		len2++;
	}
	if (len2 < len1)
		return (0);
	return (1);
}
