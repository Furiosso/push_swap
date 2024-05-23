
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include "Libft/libft.h"

typedef	struct	s_int
{
	int	number;
	struct s_int	*next;
}		t_stack;

t_stack	*new_node(int number);
void	clean(t_stack *list);
t_stack	*check_validity(int len, const char **argv);
char	**create_str(int len, const char **argv);
t_stack	*create_list(char **str);
int	ft_atol(char *str);
char	**clean_str(int len, char **str);
#endif
