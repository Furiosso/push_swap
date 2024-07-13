/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:42:30 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/13 14:59:39 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "Libft/libft.h"

typedef struct s_int
{
	char			flag;
	int				number;
	int				position;
	int				stack_pos;
	int				reverse_stack_pos;
	int				target;
	struct s_int	*prev;
	struct s_int	*next;
}		t_stack;

typedef struct s_parameters
{
	int		pos;
	int		target;
	char	move;
	int		distance;
}		t_params;

t_stack	*check_validity(int len, const char **argv);
void	sort_stack(t_stack **stack_a);
char	**create_str(int len, const char **argv);
t_stack	*create_stack(char **str);
int		list_size(t_stack *stack);
t_stack	*last_node(t_stack *stack);
char	check_order(t_stack **stack_a, t_stack **stack_b, int *size);
char	is_sorted(t_stack *stack, char check_from_the_beginning);
void	find_the_way(t_stack *stack_a, t_stack *stack_b, t_params **params);
void	set_stack_pos(t_stack *stack_a, t_stack *stack_b, int *size);
void	set_targets(t_stack *stack_a, t_stack *stack_b);
void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_params *params);
void	clean_stack(t_stack *list);
void	return_exit(char code);
void	push_stack(char *str, t_stack **stack, t_stack **node);
void	rotate(char *str, t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(char *str, t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	swap(char *str, t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack);
void	sort_3_backwards(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int size);

#endif
