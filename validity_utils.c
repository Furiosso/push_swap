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
