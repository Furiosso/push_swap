/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:45:31 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 12:48:06 by dagimeno         ###   ########.fr       */
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
		//ft_printf("%s\n", str);
		write(1, str, 2);
		write(1, "\n", 1);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(NULL, stack_a);
	rotate(NULL, stack_b);
//	ft_printf("rr\n");
	write(1, "rr\n", 3);
}
