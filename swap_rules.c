/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:47:12 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/13 13:45:05 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, t_stack **stack)
{
	int	num;
	int	pos;

	if (*stack && (*stack)->next)
	{
		num = (*stack)->number;
		pos = (*stack)->position;
		(*stack)->position = (*stack)->next->position;
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->position = pos;
		(*stack)->next->number = num;
		if (str)
		{
			if (ft_printf("%s\n", str) < 0)
				exit(7);
		}
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, char is_to_be_printed)
{
	swap(NULL, stack_a);
	swap(NULL, stack_b);
	if (is_to_be_printed)
	{
		if (ft_printf("ss\n") < 0)
			exit(8);
	}
}
