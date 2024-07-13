# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 14:08:56 by dagimeno          #+#    #+#              #
#    Updated: 2024/07/12 15:09:46 by dagimeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = push_swap.c check_validity.c create_stack.c sort_stack.c push_rules.c execute_movements.c swap_rules.c rotate_rules.c reverse_rotate_rules.c sorting_algorithms.c find_the_way.c utils.c set_params.c

CFLAGS = -Wall -Wextra -Werror

CC = cc
  
OFILES = $(CFILES:.c=.o)

NAME = push_swap

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(OFILES) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(OFILES) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OFILES)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
