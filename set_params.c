/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:48:47 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 12:49:35 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    get_position(t_stack *stack, int size);
static char    get_flag(t_stack *stack_a, t_stack *stack_b);
static int     get_max(t_stack *stack);

void    set_stack_pos(t_stack *stack_a, t_stack *stack_b, int *size)
{
        if (stack_a)
                get_position(stack_a, size[0]);
        if (stack_b)
                get_position(stack_b, size[1]);
}

static void    get_position(t_stack *stack, int size)
{
        t_stack *aux;
        int     pos;
        int     max;

        max = size;
        pos = 0;
        stack->stack_pos = pos++;
        stack->reverse_stack_pos = max--;
        aux = stack->next;
        while (pos < size)
        {
                aux->stack_pos = pos++;
                aux->reverse_stack_pos = max--;
                aux = aux->next;
        }
}

void    set_targets(t_stack *stack_a, t_stack *stack_b)
{
        t_stack *aux[2];
        int     max;
        char    flag;

        max = get_max(stack_b);
        aux[0] = stack_a;
        aux[0]->prev->next = NULL;
        while (aux[0])
        {
                flag = get_flag(aux[0], stack_b);
                if (!flag)
                        aux[0]->target = max;
                aux[1] = aux[0];
                aux[0] = aux[0]->next;
        }
        aux[1]->next = stack_a;
}

static char    get_flag(t_stack *stack_a, t_stack *stack_b)
{
        t_stack *aux[2];
        int     distance[2];
        char    flag;

        aux[0] = stack_b;
        aux[0]->prev->next = NULL;
        distance[0] = INT_MAX;
        flag = 0;
        while (aux[0])
        {
                if (aux[0]->position < stack_a->position)
                {
                        flag = 1;
                        distance[1] = stack_a->position - aux[0]->position;
                        if (distance[1] < distance[0])
                        {
                                distance[0] = distance[1];
                                stack_a->target = aux[0]->position;
                        }
                }
                aux[1] = aux[0];
                aux[0] = aux[0]->next;
        }
        aux[1]->next = stack_b;
        return (flag);
}

static int     get_max(t_stack *stack)
{
        int     max;
        int     pos;

        pos = stack->position;
        max = stack->position;
        stack = stack->next;
        while (stack->position != pos)
        {
                if (stack->position > max)
                        max = stack->position;
                stack = stack->next;
        }
        return (max);
}
