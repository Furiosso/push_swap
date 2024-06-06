
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
void	sort_stack(t_stack **stack_a);
char	**create_str(int len, const char **argv);
t_stack	*create_list(char **str);
char	**clean_str(char **str);
void	clean(t_stack *list);
void	return_exit(char code);
void	push_stack(char *str, t_stack **stack, t_stack **node);
void	rotate(char *str, t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(char *str, t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	swap(char *str, t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

#endif
