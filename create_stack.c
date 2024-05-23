#include "push_swap.h"
#include <stdio.h>

char	**clean_str(int len, char **str);
void	clean(t_stack *list);

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
			return (clean_str(i - 1, str));
		i++;
	}
	i = 0;
	while (str[i])
		printf("%s | ", str[i++]);
	printf("\n");
	return (str);
}

t_stack	*create_list(char **str)
{
	t_stack	*stack_a;
	t_stack *aux;
	int	cont;

	stack_a = new_node(ft_atol(str[0]));
	if (!stack_a)
		return (NULL);
	aux = stack_a;
	cont = 1;
	while (str[cont])
	{
		aux->next = new_node(ft_atol(str[cont++]));
		if (!aux->next)
		{
			clean(stack_a);
			return (NULL);
		}
		aux = aux->next;
	}
	return (stack_a);
}

char	**clean_str(int len, char **str)
{
	int	i;
	
	i = 0;
	while (i < len)
		free(str[i++]);
	free(str);
	return (NULL);
}

void	clean(t_stack *list)
{
	t_stack	*aux;

	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
