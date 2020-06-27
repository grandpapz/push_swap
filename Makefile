# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelida <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 19:24:32 by lelida            #+#    #+#              #
#    Updated: 2020/06/27 18:46:05 by lelida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
SRC1 = push_swap.c devide.c init.c op.c part_sort_a.c \
		part_sort_b.c push_top.c push_top_b.c sort.c sort2.c \
		sort_b.c sort_b2.c arg_splt.c
SRC2 = checker.c init.c op.c arg_splt.c sort.c \
		part_sort_a.c part_sort_b.c sort2.c sort_b.c sort_b2.c \
		push_top.c push_top_b.c	
OBJ1 = $(patsubst %.c, %.o, $(SRC1))
OBJ2 = $(patsubst %.c, %.o, $(SRC2))
LIBFT = -I libft/includes -L libft -lft
CC = gcc
FLG = -Wall -Wextra -Werror

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1)
	@echo "$(GREEN) Compiling libft $(RESET)"
	@make -C libft/
	@echo "$(GREEN) Compiling push_swap $(RESET)"
	@$(CC) $(FLG) -I libft/includes -c $(SRC1)
	@$(CC) -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2): $(SRC2)
	@echo "$(GREEN) Compiling checker $(RESET)"
	@$(CC) $(FLG) -I libft/includes -c $(SRC2)
	@$(CC) -o $(NAME2) $(OBJ2) $(LIBFT)

clean:
	@echo "$(RED) Remove .o files $(RESET)"
	@make -C libft/ clean
	@rm -f $(OBJ1) $(OBJ2)

fclean: clean
	@echo "$(RED) Remove libft & $(NAME1) & $(NAME2) $(RESET)"
	@make -C libft/ fclean
	@rm -f $(NAME1) $(NAME2)

re:	clean fclean all
