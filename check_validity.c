#include "push_swap.h"
#include <stdio.h>

static void	check_integers(char **str);
int	ft_atol(char *str);
static void	check_duplicity(t_stack *stack_a);
static void	return_exit(int code);

t_stack	*check_validity(int len, const char **argv)
{
	char	**str;
	t_stack	*stack_a;
	int	cont;

	if (len == 2)
		str = ft_split(argv[1], ' ');
	else
		str = create_str(len, argv);
	if (!str)
		return (NULL);
	cont = 0;
	while (str[cont])
		printf(" %s -", str[cont++]);
       	printf("\n");	
	check_integers(str);
	stack_a = create_list(str);
	clean_str(len, str);
	if (!stack_a)
		return (NULL);
	check_duplicity(stack_a);
	return (stack_a);
}

static void	check_integers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < 48 || str[i][j] > 57)
			{
				if ((j == 0 && str[i][j] == 45)
						|| (j == 0 && str[i][j] == 43))
				{
					j++;
					continue ;
				}
				return_exit(1);
			}
			j++;
		}
		i++;
	}
}

int	ft_atol(char *str)
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

static void	check_duplicity(t_stack *stack_a)
{
	t_stack	*aux1;
	t_stack	*aux2;
	int	i;
	int	j;

	aux1 = stack_a;
	i = 0;
	while (aux1)
	{
		aux2 = stack_a;
		j = 0;
		while (aux2)
		{
			if (i == j++)
			{
				aux2 = aux2->next;
				continue ;
			}
			if (aux1->number == aux2->number)
				return_exit(3);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
		i++;
	}
}

static void	return_exit(int code)
{
	write(1, "Error\n", 6);
	exit(code);
}
