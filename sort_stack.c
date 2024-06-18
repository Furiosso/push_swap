#include "push_swap.h"
#include <stdio.h>

void	sort_stack(t_stack **stack_a);
char	check_order(t_stack *stack);
void	stablish_position(t_stack **stack);
void	k_sort(t_stack **stack_a, t_stack **stack_b);
void	compare_sort(t_stack **stack_a, t_stack **stack_b);
void	divide_sort(t_stack **stack_a, t_stack **stack_b);
void	bubble_sort(t_stack **stack_a, t_stack **stack_b);
void	custom_sort(t_stack **stack_a, t_stack **stack_b);
int	find_middle(t_stack *stack);
size_t	list_size(t_stack *stack);
t_stack	*last_node(t_stack *stack);

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	//t_stack	*aux;

	stablish_position(stack_a);
	stack_b = NULL;
	if (check_order(*stack_a))
		return ;
	k_sort(stack_a, &stack_b);
	/*aux = *stack_a;
	while (aux)
	{
		printf(" %d |", aux->number);
		aux = aux->next;
	}
	printf("\n");*/
	//custom_sort(stack_a, &stack_b);
	//compare_sort(stack_a, &stack_b);
	//divide_sort(stack_a, &stack_b);
	//if (check_order(stack_b))
	//	printf("OK");
	//else
	//	printf("KO");
	//bubble_sort(stack_a, &stack_b);
}

void	k_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	pos;
	size_t	steps;
	size_t	steps_up;
	size_t	reverse_steps;
	t_stack	*aux;

	pos = 0;
	while (*stack_a && !check_order(*stack_a))
	{
		aux = *stack_a;
		steps = 0;
		while (aux)
		{
			if (aux->position < pos + 10)
				break ;
			steps++;
			aux = aux->next;
		}
		steps_up = steps;
		reverse_steps = 0;
		while (aux) 
		{
			if (aux->position < pos + 10)
				reverse_steps = steps_up;
			steps_up++;
			aux = aux->next;
		}
		if (steps < list_size(*stack_a) - reverse_steps)
		{
			while ((*stack_a)->position > pos + 10)
				rotate("ra", stack_a);
		}
		else
		{
			while ((*stack_a)->position > pos + 10)
				reverse_rotate("rra", stack_a);
		}
		push_stack("pb", stack_b, stack_a);
		pos++;
	}
	/*while (*stack_a)
	{
		printf("%zu: %d\n", (*stack_a)->position, (*stack_a)->number);
		*stack_a = (*stack_a)->next;
	}*/
	pos = list_size(*stack_b);
	while (*stack_b)
	{
		aux = *stack_b;
		steps = 0;
		while (aux)
		{
			if (aux->position == pos)
				break ;
			steps++;
			aux = aux->next;
		}
		if (steps > list_size(*stack_b) / 2)
		{
			while ((*stack_b)->position != pos)
				reverse_rotate("rrb", stack_b);
		}
		else
		{
			while ((*stack_b)->position != pos)
				rotate("rb", stack_b);
		}
		push_stack("pa", stack_a, stack_b);
		pos--;
	}
	/*while (*stack_a)
	{
		printf("%zu: %d\n", (*stack_a)->position, (*stack_a)->number);
		*stack_a = (*stack_a)->next;
	}*/
}

void	stablish_position(t_stack **stack)
{	
	size_t	pos;
	t_stack	*aux1;
	t_stack	*aux2;

	aux1 = *stack;
	while (aux1)
	{
		pos = 1;
		aux2 = *stack;
		while (aux2)
		{
			if (aux1->number == aux2->number)
			{
				aux2 = aux2->next;
				continue ;
			}
			if (aux2->number < aux1->number)
				pos++;
			aux2 = aux2->next;
		}
		aux1->position = pos;
		aux1 = aux1->next;
	}
	/*aux1 = *stack;
	while (aux1)
	{
		printf("%zu: %d\n", aux1->position, aux1->number);
		aux1 = aux1->next;
	}*/
}

void	divide_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len;
	size_t  pos;
	int	steps;
	int	reverse_steps;
	int	steps_up;
	t_stack	*aux;

	pos = list_size(*stack_a) / 2;
	len = pos;
	while (len--)
	{
		steps = 0;
		aux = *stack_a;
		while (aux)
		{
			if (aux->position < pos)
				break;
			aux = aux->next;
			steps++;
		}
		steps_up = steps;
		reverse_steps = 0;
		while (aux)
		{
			if (aux->position < pos)
				reverse_steps = steps_up;
			aux = aux->next;
			steps_up++;
		}
		if (steps < list_size(*stack_a) - reverse_steps)
		{
			while ((*stack_a)->position > pos)
				rotate("ra", stack_a);
		}
		else
		{
			while ((*stack_a)->position > pos)
				reverse_rotate("rra", stack_a);
		}
		push_stack("pb", stack_b, stack_a);
	}
	/*int	steps_a;
	int	steps_b;

	len = pos;
	aux = *stack_a;
	steps = 0;
	while (aux)
	{
		if (aux->position == list_size(*stack_a) * 2)
			break ;
		steps++;
	}
	steps_a = steps;
	if (steps >= list_size(*stack_a) / 2)
		steps_a = -steps;
	aux = *stack_b;
	steps = 0;
	while (aux)
	{
		if (aux->position == 1)
			break ;
		steps++;
	}
	steps_b = steps
	if (steps >= list_size(*stack_b) / 2)
		steps_b = -steps;*/
	len = list_size(*stack_a) * 2;
	while ((*stack_a)->position != len)
		rotate("ra", stack_a);
	while ((*stack_b)->position != 1)
		rotate("rb", stack_b);
	len = list_size(*stack_a);
	while (len--)
	{
		if ((*stack_a)->next->position == (*stack_a)->position + 1)
		{

	}

}

void	compare_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;
	int	middle;
	//t_stack	*aux;

	middle = find_middle(*stack_a);
	//printf("middle: %d\n", middle);
	size = list_size(*stack_a);
	//printf("size: %zu\n", size);
	while (size--)
	{
		if ((*stack_a)->number < middle)
		{
			push_stack("pb", stack_b, stack_a);
			if (*stack_b && (*stack_b)->next && (*stack_b)->number < (*stack_b)->next->number)
				swap("sb", stack_b);
		}
		else
			rotate("ra", stack_a);
	}
	/*aux = *stack_b;
	printf("size stack_b: %zu\n", list_size(*stack_b));
	printf("size stack_a: %zu\n", list_size(*stack_a));
	printf("Stack b: ");
	while (aux)
	{
		printf(" %d |", aux->number);
		aux = aux->next;
	}
	printf("\n");*/
}

int	find_middle(t_stack *stack)
{
	size_t	len;
	size_t 	con;
	t_stack	*aux;
	t_stack	*aux2;

	len = list_size(stack);
	//printf("Size: %zu\n", len);
	aux = stack;
	while (aux)
	{
		aux2 = stack;
		con = 0;
		while (aux2)
		{
			if (aux->number < aux2->number)
				con++;
			aux2 = aux2->next;
		}
		//printf("Con: %zu\n", con);
		if (con == len / 2)
			break ;
		aux = aux->next;
	}
	//printf("Con: %zu\n", con);
	return (aux->number + 1);
}

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
		if (stack->position != stack->next->position - 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

