/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:41:37 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/13 18:09:17 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int len, const char **argv)
{
	t_stack	*stack_a;

	if (len < 2)
		return (0);
	stack_a = check_validity(len, argv);
	if (!stack_a)
		return (0);
	sort_stack(&stack_a);
	clean_stack(stack_a);
}
