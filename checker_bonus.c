#include "push_swap.h"

static void	check_list(t_stack **stack_a, t_stack **stack_b);
static void	check_line(char *line);
static void	execute_line(t_stack **stack_a, t_stack **stack_b, char *line);

int	main(int len, const char **argv)
{
		t_stack	*stack_a;
		t_stack *stack_b;

		if (len < 2)
				return (0);
		stack_a = check_validity(len, argv);
		if (!stack_a)
				return (0);
		stack_b = NULL;
		check_list(&stack_a, &stack_b);
		if (stack_a)
			clean_stack(stack_a);
		if (stack_b)
				clean_stack(stack_b);
}

static void check_list(t_stack **stack_a, t_stack **stack_b)
{
		char	*line;

		line = get_next_line(0);
		if (line)
		{
			check_line(line);
			execute_line(stack_a, stack_b, line);
		}
		while (line)
		{
				line = get_next_line(0);
				if (line)
				{
					check_line(line);
					execute_line(stack_a, stack_b, line);
				}
		}
		if (is_sorted(*stack_a, 1) && !*stack_b)
				ft_printf("OK\n");
		else
				ft_printf("KO\n");
}

static void	check_line(char *line)
{
		if (ft_strncmp(line, "ra\n", 3) != 0
			&& ft_strncmp(line, "rb\n", 3) != 0
			&& ft_strncmp(line, "rr\n", 3) != 0
			&& ft_strncmp(line, "rra\n", 4) != 0
			&& ft_strncmp(line, "rrb\n", 4) != 0
			&& ft_strncmp(line, "rrr\n", 4) != 0
			&& ft_strncmp(line, "pa\n", 3) != 0
			&& ft_strncmp(line, "pb\n", 3) != 0
			&& ft_strncmp(line, "sa\n", 3) != 0
			&& ft_strncmp(line, "sb\n", 3) != 0
			&& ft_strncmp(line, "ss\n", 3) != 0)
				return_exit(17);
}

static void	execute_line(t_stack **stack_a, t_stack **stack_b, char *line)
{
		if (!(ft_strncmp(line, "ra\n", 3)))
				rotate(NULL, stack_a);
		if (!(ft_strncmp(line, "rb\n", 3)))
				rotate(NULL, stack_b);
		if (!(ft_strncmp(line, "rr\n", 3)))
				rr(stack_a, stack_b, 0);
		if (!(ft_strncmp(line, "rra\n", 4)))
				reverse_rotate(NULL, stack_a);
		if (!(ft_strncmp(line, "rrb\n", 4)))
				reverse_rotate(NULL, stack_b);
		if (!(ft_strncmp(line, "rrr\n", 4)))
				rrr(stack_a, stack_b, 0);
		if (!(ft_strncmp(line, "pa\n", 3)))
				push_stack(NULL, stack_a, stack_b);
		if (!(ft_strncmp(line, "pb\n", 3)))
				push_stack(NULL, stack_b, stack_a);
		if (!(ft_strncmp(line, "sa\n", 3)))
				swap(NULL, stack_a);
		if (!(ft_strncmp(line, "sb\n", 3)))
				swap(NULL, stack_b);
		if (!(ft_strncmp(line, "ss\n", 3)))
				ss(stack_a, stack_b, 0);
}
