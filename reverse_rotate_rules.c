/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rules.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:44:46 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/13 13:43:50 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(char *str, t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->prev;
	if (str)
	{
		if (ft_printf("%s\n", str) < 0)
			exit(12);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(NULL, stack_a);
	reverse_rotate(NULL, stack_b);
	if (ft_printf("rrr\n") < 0)
		exit(13);
}
