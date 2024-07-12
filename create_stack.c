/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:39:53 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 14:53:57 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol(char *str);
static char	**clean_str(char **str);
void		clean_stack(t_stack *list);

char	**create_str(int len, const char **argv)
{
	char	**str;
	int	i;

	str = ft_calloc(len, sizeof(char *));
	if (!str)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		str[i - 1] = ft_strdup(argv[i]);
		if (!str[i - 1])
			return (clean_str(str));
		i++;
	}
	return (str);
}

t_stack	*create_stack(char **str)
{
	t_stack	*stack_a;
	t_stack *aux;
	int	cont;

	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->number = ft_atol(str[0]);
	aux = stack_a;
	cont = 1;
	while (str[cont])
	{
		aux->next = ft_calloc(1, sizeof(t_stack));
		if (!aux->next)
		{
			clean_stack(stack_a);
			return (NULL);
		}
		aux->next->prev = aux;
		aux = aux->next;
		aux->number = ft_atol(str[cont++]);
	}
	clean_str(str);
	return (stack_a);
}

static int	ft_atol(char *str)
{
	long	num;
	int	result;
	char	odd;

	num = 0;
	odd = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			odd = 1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if (odd)
		num = -num;
	if (num > INT_MAX || num < INT_MIN)
		return_exit(2);
	result = num;
	return (result);
}

static char	**clean_str(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

void	clean_stack(t_stack *list)
{
	t_stack	*aux;

	list->prev->next = NULL;	
	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
