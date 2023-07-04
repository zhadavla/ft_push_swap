#pragma once

#define bool int
#define true 1
#define false 0

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "libft/libft.h"
#include "stack/stack.h"
#include "alg/algorithm.h"
# include <unistd.h>

// function to fill stack_a with integers received
void fill_stack_a(t_stack **stack_a, int argc, char **argv);

// functions to check the errors
int error_check(int argc, char **argv);

int digit_check(char *lst);

int dup_check(int argc, char **lst, int flag);

int range_check(char *lst);

// functions to free memory
void ft_free_list(t_stack **stack);

void ft_free_arr(char **arr);

void ft_free(t_stack **stack_a, t_stack **stack_b);

// functions to get min and max value, and pointer to node with min_max value
int find_max_value(t_stack *stack);

int find_min_value(t_stack *stack);

t_stack *get_max_elem(t_stack *stack);

t_stack *get_min_elem(t_stack *stack);

// head function to sort the stack
void sort_three(t_stack **stack_a);

void sort_five(t_stack **stack_a, t_stack **stack_b);

void sort(t_stack **stack_a, t_stack **stack_b);

// get index functions
int find_mid_index(t_stack *stack_a);

t_stack *get_last_elem(t_stack *stack);

int get_index_before(t_stack *elem, t_stack *stack_b);

// check if sorted
bool is_not_sorted(t_stack *stack);

int check_if_b_sorted(t_stack *stack);

// functions to calculate the weight
void get_weight_ba(t_stack **stack_a, t_stack **stack_b);

int get_future_index_in_a(int num, t_stack *stack_a);

void assign_weights(t_stack **stack_a, t_stack **stack_b);

int get_future_index_in_b(int num, t_stack *stack_b);

int calculate_weight(t_stack *elem_a, t_stack *stack_a,
                     t_stack *stack_b, int future_index);

// bonus checker
void instructions_one(const char *instr, t_stack **stack_a, t_stack **stack_b);

void instructions_two(const char *instr, t_stack **stack_a, t_stack **stack_b);


t_stack *get_input(int argc, char **argv);