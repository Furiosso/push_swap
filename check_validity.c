#include "push_swap.h"

static void	check_integers(char **str);
static void	stablish_position(t_stack *stack);
static void	check_duplicity(t_stack *stack_a);
void		return_exit(char code);

t_stack	*check_validity(int len, const char **argv)
{
	char	**str;
	t_stack	*stack_a;
	t_stack	*last;

	if (len == 2)
		str = ft_split(argv[1], ' ');
	else
		str = create_str(len, argv);
	if (!str)
		return (NULL);
	check_integers(str);
	stack_a = create_list(str);
	if (!stack_a)
		return (NULL);
	check_duplicity(stack_a);
	stablish_position(stack_a);
	last = last_node(stack_a);
	last->next = stack_a;
	stack_a->prev = last;
	return (stack_a);
}

static void	check_integers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (!ft_strlen(str[i]))
			return_exit(4);
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

void	return_exit(char code)
{
	//ft_printf("Error\n");
	write(1, "Error\n", 6);
	exit(code);
}

static void	stablish_position(t_stack *stack)
{
        int	pos;
        t_stack	*aux1;
        t_stack	*aux2;

        aux1 = stack;
        while (aux1)
        {
                pos = 1;
                aux2 = stack;
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
}
