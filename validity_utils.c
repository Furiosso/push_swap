/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:10:51 by dagimeno          #+#    #+#             */
/*   Updated: 2024/09/18 11:52:47 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_spaces(const char **argv, int con);

int	count_strings(int len, const char **argv)
{
	int	cont[3];

	cont[0] = 0;
	while (argv[++cont[0]])
	{
		if (ft_strchr(argv[cont[0]], ' '))
		{
			check_spaces(argv, cont[0]);
			cont[1] = -1;
			cont[2] = 0;
			while (argv[cont[0]][cont[2]])
			{
				while (argv[cont[0]][cont[2]] == ' ')
					cont[2]++;
				if (argv[cont[0]][cont[2]] && argv[cont[0]][cont[2]] != ' ')
					cont[1]++;
				while (argv[cont[0]][cont[2]] && argv[cont[0]][cont[2]] != ' ')
					cont[2]++;
			}
			len += cont[1];
		}
	}
	return (len);
}

static void	check_spaces(const char **argv, int con)
{
	int	i;

	i = 0;
	while (argv[con][i])
	{
		if (argv[con][i] != ' ')
			return ;
		i++;
	}
	return_exit(18);
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

long	get_num(char *str, size_t len)
{
	long	num;

	num = 0;
	while (*str > 47 && *str < 58)
	{
		num = num * 10 + *str - 48;
		str++;
		len++;
	}
	if (len > 11)
		return_exit(10);
	return (num);
}
