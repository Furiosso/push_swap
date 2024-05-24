
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "Libft/libft.h"

typedef	struct	s_int
{
	int	number;
	struct s_int	*next;
}		t_stack;

t_stack	*check_validity(int len, const char **argv);
char	**create_str(int len, const char **argv);
t_stack	*create_list(char **str);
char	**clean_str(char **str);
void	clean(t_stack *list);
void	return_exit(char code);

#endif
