# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 12:47:34 by mnurlybe          #+#    #+#              #
#    Updated: 2023/05/29 20:30:28 by mnurlybe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

MAIN_SOURSCES = srcs/main.c

MANDATORY_SOURCES = srcs/libft/ft_atoi.c \
	srcs/stack/one_stack_operations.c \
	srcs/libft/ft_split.c \
	srcs/libft/ft_strlen.c \
	srcs/algorithm/bool_utils.c \
	srcs/libft/ft_lstnew.c \
	srcs/libft/ft_lstadd_back.c \
	srcs/libft/ft_lstadd_front.c \
	srcs/libft/ft_lstsize.c \
	srcs/ft_stack/fill_stack_a.c \
	srcs/error_main.c \
	srcs/error_checks.c \
	srcs/free_memory.c \
	srcs/stack/stack_operations_a.c \
	srcs/stack/stack_operations_b.c \
	srcs/stack/two_stacks_operations.c \
	srcs/stack/stack_suboperations.c \
	srcs/algorithm/small_sort.c \
	srcs/algorithm/min_max_value.c \
	srcs/algorithm/get_index.c \
	srcs/stack/stack_oper_adds.c \
	srcs/algorithm/sort.c \
	srcs/algorithm/move_b_to_a.c \
	srcs/algorithm/move_a_to_b.c \
	srcs/algorithm/score.c \
	srcs/utils/array_to_stack.c \

BONUS_SOURCES =	srcs/libft/get_next_line.c \
	srcs/libft/get_next_line_utils.c \
	bonus/checker.c \
	bonus/instructions_bonus_a.c \
	bonus/instructions_bonus_b.c \
	bonus/instructions_bonus_ab.c \
	bonus/perform_instructions.c

CFLAGS = -Wall -Wextra -Werror

MY_HEADER = ./includes/

MAIN_OBJECTS = $(MAIN_SOURSCES:.c=.o)
MAND_OBJECTS = $(MANDATORY_SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

.c.o:
	gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o ${<:.c=.o}

$(NAME): $(MAND_OBJECTS) $(MAIN_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(MAND_OBJECTS) $(MAIN_OBJECTS)

$(BONUS): $(MAND_OBJECTS) $(BONUS_OBJECTS)
	cc $(CFLAGS) -o $(BONUS) $(MAND_OBJECTS) $(BONUS_OBJECTS)


all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	rm -f $(MAIN_OBJECTS) $(MAND_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean fclean re
