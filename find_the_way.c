#include "push_swap.h"

void		find_down(t_stack *stack_a, t_stack *stack_b, t_params **params);
void		find_backwards(t_stack *stack_a, t_stack *stack_b, t_params **params);
t_params	set_params(t_stack **pointers);
t_params	compare_distances(int *distances, t_stack **pointers);

void		find_the_way(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	(*params)->distance = INT_MAX;
	find_down(stack_a, stack_b, params);
	find_backwards(stack_a->prev, stack_b, params);
}

void		find_down(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	t_stack		*aux[2];
	t_params	aux_param;

	aux[0] = stack_b;
	while (aux[0] != stack_b || (aux[0] == stack_b && !stack_b->flag))
	{
		aux[1] = stack_a;
		while (aux[1] != stack_a || (aux[1] == stack_a && !stack_a->flag))
		{
			if (aux[0]->position == aux[1]->target)
			{
				aux_param = set_params(aux);
				if (aux_param.distance < (*params)->distance)
					**params = aux_param;
				break;
			}
			aux[1] = aux[1]->next;
			stack_a->flag = 1;
		}
		stack_a->flag = 0;
		stack_b->flag = 1;
		aux[0] = aux[0]->next;
	}
	stack_b->flag = 0;
}

void		find_backwards(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	t_stack		*aux[2];
	t_params	aux_param;

	aux[0] = stack_b;
	while (aux[0] != stack_b || (aux[0] == stack_b && !stack_b->flag))
	{
		aux[1] = stack_a;
		while (aux[1] != stack_a || (aux[1] == stack_a && !stack_a->flag))
		{
			if (aux[0]->position == aux[1]->target)
			{
				aux_param = set_params(aux);
				if (aux_param.distance < (*params)->distance)
					**params = aux_param;
				break;
			}
			aux[1] = aux[1]->prev;
			stack_a->flag = 1;
		}
		stack_a->flag = 0;
		stack_b->flag = 1;
		aux[0] = aux[0]->next;
	}
	stack_b->flag = 0;
}

t_params	set_params(t_stack **pointers)
{
	int	distances[4];

	if (pointers[1]->stack_pos > pointers[0]->stack_pos)
		distances[0] = pointers[1]->stack_pos;
	else
		distances[0] = pointers[0]->stack_pos;
	if (pointers[1]->reverse_stack_pos > pointers[0]->reverse_stack_pos)
		distances[1] = pointers[1]->reverse_stack_pos;
	else
		distances[1] = pointers[0]->reverse_stack_pos;
	distances[2] = pointers[1]->stack_pos + pointers[0]->reverse_stack_pos;
	distances[3] = pointers[1]->reverse_stack_pos + pointers[0]->stack_pos;
	//for (int i = 0; i < 4; i++)
		//printf("distances[%d] = %d\n", i, distances[i]);
	//printf("\n");
	return (compare_distances(distances, pointers));
}

t_params	compare_distances(int *distances, t_stack **pointers)
{
	t_params	params;
	int		min;
	int		index;
	int		i;

	min = INT_MAX;
	index = 0;
	i = 0;
	while (i < 4)
	{
		if (distances[i] < min)
		{
			min = distances[i];
			index = i;
		}
		i++;
	}
	params.pos = pointers[1]->position;
	params.target = pointers[1]->target;
	params.distance = min;
	params.move = index + 1;
	return (params);
}
