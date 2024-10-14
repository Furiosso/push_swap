/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:39:53 by dagimeno          #+#    #+#             */
/*   Updated: 2024/09/18 11:52:50 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	split_arg(char **str, const char **argv, int *con);
static int	ft_atol(char *str, char **list, t_stack *stack);
//char		**clean_str(char **str);

char	**create_str(int len, const char **argv)
{
	char	**str;
	int		con[2];

	str = ft_calloc(len, sizeof(char *));
	if (!str)
		return (NULL);
	con[0] = 0;
	con[1] = 0;
	while (argv[++con[0]])
	{
		if (ft_strchr(argv[con[0]], ' '))
		{
			con[1] = split_arg(str, argv, con);
			if (con[1] < 0)
				return (clean_str(str));
			continue ;
		}
		str[con[1]] = ft_strdup(argv[con[0]]);
		if (!str[con[1]++])
			return (clean_str(str));
	}
	return (str);
}

static int	split_arg(char **str, const char **argv, int *con)
{
	char	**aux;
	int		i;
	int		j;

	aux = ft_split(argv[con[0]], ' ');
	if (!aux)
		return (-1);
	i = con[1];
	j = 0;
	while (aux[j])
	{
		str[i] = ft_strdup(aux[j++]);
		if (!str[i++])
			return (-1);
	}
	clean_str(aux);
	return (i);
}

t_stack	*create_stack(char **str)
{
	t_stack	*stack_a;
	t_stack	*aux;
	int		cont;

	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->number = ft_atol(str[0], str, stack_a);
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
		aux->number = ft_atol(str[cont++], str, stack_a);
	}
	clean_str(str);
	return (stack_a);
}

static int	ft_atol(char *str, char **list, t_stack *stack)
{
	long	num;
	int		result;
	char	negative;
	size_t	len;

	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	negative = 0;
	len = 0;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
		{
			negative = 1;
			len++;
		}
		str++;
	}
	num = get_num(str, len, list, stack);
	if (negative)
		num = -num;
	if (num > INT_MAX || num < INT_MIN)
		free_and_exit(list, stack);
	result = num;
	return (result);
}

char	**clean_str(char **str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
			free(str[i++]);
		free(str);
	}
	return (NULL);
}
