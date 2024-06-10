#include "push_swap.h"
#include <stdio.h>

void	sort_stack(t_stack **stack_a);
char	check_order(t_stack *stack);
//void	radix_sort(stack_a, &stack_b);
void	bubble_sort(t_stack **stack_a, t_stack **stack_b);
void	custom_sort(t_stack **stack_a, t_stack **stack_b);
size_t	list_size(t_stack *stack);
t_stack	*last_node(t_stack *stack);

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	//t_stack	*aux;

	stack_b = NULL;
	if (check_order(*stack_a))
		return ;
	/*aux = *stack_a;
	while (aux)
	{
		printf(" %d |", aux->number);
		aux = aux->next;
	}
	printf("\n");*/
	custom_sort(stack_a, &stack_b);
	//radix_sort(stack_a, &stack_b);
	//bubble_sort(stack_a, &stack_b);
	//swap("sa", stack_a);
	//push_stack("pb", &stack_b, stack_a);
	//push_stack("pb", &stack_b, stack_a);
	//push_stack("pb", &stack_b, stack_a);
	//rr(stack_a, &stack_b);
	//rrr(stack_a, &stack_b);
	//swap("sa", stack_a);
	//push_stack("pa", stack_a, &stack_b);
	//push_stack("pa", stack_a, &stack_b);
	//push_stack("pa", stack_a, &stack_b);
}
/*
void	radix_sort(stack_a, &stack_b)
{

}*/

void	custom_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	t_stack	*aux;
	size_t	len;	

	while (!check_order(*stack_a) && list_size(*stack_a) > 2)
	{
		min = (*stack_a)->number;
		aux = (*stack_a)->next;
		while (aux)
		{
			if (aux->number < min)
				min = aux->number;
			aux = aux->next;
		}
		aux = *stack_a;
		len = 0;
		while (aux->number != min)
		{
			len++;
			aux = aux->next;
		}
		while ((*stack_a)->number != min)
		{
			if (len <= list_size(*stack_a) / 2)
	       			rotate("ra", stack_a);
			else
				reverse_rotate("rra", stack_a);
		}
		if (check_order(*stack_a) && !*stack_b)
			return ;
		push_stack("pb", stack_b, stack_a);
		/*aux = *stack_a;
		printf("Stack a: ");
		while (aux)
		{
			printf(" %d |", aux->number);
			aux = aux->next;
		}
		printf("\n");*/
	}
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap("sa", stack_a);
	while (list_size(*stack_b) > 0)
		push_stack("pa", stack_a, stack_b);
}

void	bubble_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;
	//t_stack	*aux;

	while (list_size(*stack_a) > 1)
	{
		push_stack("pb", stack_b, stack_a);
		i = 0;
		while (i++ <= list_size(*stack_a))
		{
			if ((*stack_a)->number < (*stack_b)->number)
			{
				push_stack("pa", stack_a, stack_b);
				swap("sa", stack_a);
				push_stack("pb", stack_b, stack_a);
			}
			rotate("ra", stack_a);
		}
		rotate("ra", stack_a);
		/*aux = *stack_a;
		printf("Stack a: ");
		while (aux)
		{
			printf(" %d |", aux->number);
			aux = aux->next;
		}
		printf("\n");
		printf("Stack b: ");
		aux = *stack_b;
		while (aux)
		{
			printf(" %d |", aux->number);
			aux = aux->next;
		}
		printf("\n");*/
	}
	while (0 < list_size(*stack_b))
		push_stack("pa", stack_a, stack_b);
}

size_t	list_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*last_node(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}		


char	check_order(t_stack *stack)
{
	//printf("check order accedido\n");
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
