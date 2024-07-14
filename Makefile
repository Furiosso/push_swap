# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagimeno <dagimeno@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 14:08:56 by dagimeno          #+#    #+#              #
#    Updated: 2024/07/13 18:19:15 by dagimeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMON_FILES = check_validity.c create_stack.c push_rules.c swap_rules.c rotate_rules.c reverse_rotate_rules.c set_params.c utils.c

CFILES = push_swap.c sort_stack.c execute_movements.c sorting_algorithms.c find_the_way.c

BONUSFILES = checker_bonus.c

CFLAGS = -Wall -Wextra -Werror -fsanitize=address,leak -g

CC = cc

OCOMMONFILES = $(COMMON_FILES:.c=.o)
  
OFILES = $(CFILES:.c=.o)

OBONUSFILES = $(BONUSFILES:.c=.o)

NAME = push_swap

BONUS_NAME = checker_bonus

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(OFILES) $(OCOMMONFILES) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) $(OCOMMONFILES) $(OFILES) $(LIBFT) -o $(NAME)

bonus:$(OBONUSFILES) $(OCOMMONFILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(OCOMMONFILES) $(OBONUSFILES) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OFILES) $(OBONUSFILES) $(OCOMMONFILES)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
