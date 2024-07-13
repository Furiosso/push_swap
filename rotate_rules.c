/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:45:31 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/13 13:44:29 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char *str, t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (str)
	{
		if (ft_printf("%s\n", str) < 0)
			exit(10);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(NULL, stack_a);
	rotate(NULL, stack_b);
	if (ft_printf("rr\n") < 0)
		exit(11);
}
