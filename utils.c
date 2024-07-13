/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:58:26 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 13:00:04 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min(t_stack *stack);

int     list_size(t_stack *stack)
{
        int     i;
        int     pos;
        t_stack *aux;

        if (!stack)
                return (0);
        pos = stack->position;
        aux = stack->next;
        i = 1;
        while (aux->position != pos)
        {
                i++;
                aux = aux->next;
        }
        return (i);
}

t_stack *last_node(t_stack *stack)
{
        while (stack->next)
                stack = stack->next;
        return (stack);
}

char    check_order(t_stack **stack_a, t_stack **stack_b, int *size)
{
        t_stack *aux;
        int     pos;

        if (!*stack_a || !(*stack_a)->next)
                return (1);
        set_stack_pos(*stack_a, *stack_b, size);
        aux = find_min(*stack_a);
        pos = aux->position;
        while (aux->next->position != pos)
        {
                if (aux->position > aux->next->position)
                        return (0);
                aux = aux->next;
        }
        aux = aux->next;
        while (aux != *stack_a)
        {
                if (aux->reverse_stack_pos > aux->stack_pos)
                        rotate("ra", stack_a);
                else
                        reverse_rotate("rra", stack_a);
        }
        set_stack_pos(*stack_a, *stack_b, size);
        return (1);
}

static t_stack *find_min(t_stack *stack)
{
        t_stack *aux[2];
        int     min;
        int     pos;

        min = INT_MAX;
        aux[0] = stack;
        pos = stack->position;
        while (aux[0]->position != pos
		|| (aux[0]->position == pos && !stack->flag))
        {
                if (aux[0]->position < min)
                {
                        min = aux[0]->position;
                        aux[1] = aux[0];
                }
                stack->flag = 1;
                aux[0] = aux[0]->next;
        }
        stack->flag = 0;
        return (aux[1]);
}

char	is_sorted(t_stack *stack, char check_from_the_beginning)
{
	t_stack	*aux;
	int	pos;

	if (check_from_the_beginning && stack->position != 1)
		return (0);
	pos = stack->position;
	aux = stack;
	while (aux->next->position != pos)
	{
		if (aux->position + 1 != aux->next->position)
			return (0);
		aux = aux->next;
	}
	return (1);
}
