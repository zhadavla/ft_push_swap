cmake_minimum_required(VERSION 3.25)
project(ft_push_swap C)

set(CMAKE_C_STANDARD 11)

add_executable(ft_push_swap
        src/main.c src/ft_stack/array_to_stack.c src/ft_stack/print_stack.c
        src/ft_stack/one_stack_operations.c src/ft_stack/stack_operations_times.c
        src/ft_stack/two_stacks_operations.c src/ft_stack/stack_utils.c src/libft/chars_to_ints.c
        src/libft/ft_atoi.c src/libft/ft_itoa.c src/libft/ft_strlen.c src/ft_algorithm/assign_weights.c
        src/ft_algorithm/push_swap.c src/libft/ft_strdup.c src/ft_algorithm/utilits.c src/ft_algorithm/move.c src/ft_algorithm/bool_utils.c src/ft_algorithm/three_sort.c)
