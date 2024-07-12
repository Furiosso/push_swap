/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:41:37 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 15:08:18 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int len, const char **argv)
{
	t_stack	*stack_a;
	//t_stack	*aux;

	if (len < 2)
		return (0);
	stack_a = check_validity(len, argv);
	if (!stack_a)
		return (0);
	sort_stack(&stack_a);
	/*size_t size = list_size(stack_a);
	aux = stack_a;
	while (size--)
	{
		ft_printf(" %d: %d\n", aux->position, aux->number);
		aux = aux->next;
	}*/
	clean_stack(stack_a);
	return (0);
}
