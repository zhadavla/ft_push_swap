#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "../push_swap.h"
#include "../libft/libft.h"

/***************bool utilits***************/
bool in_first_half_a(t_stack *node, t_stack *stack_a);
bool in_first_half_b(t_stack *stack_b, int index_in_b);
bool in_first_second(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool in_second_first(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

/***************move utilits***************/
void move_first_second(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_second_first(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_second_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_first_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);

/***************sort utilits***************/
bool is_not_sorted(t_stack *stack);
t_stack *find_by_value(t_stack *stack, int value);
int find_max_value(t_stack *stack);
int find_min_value(t_stack *stack);
t_stack *get_max_elem(t_stack *stack);
t_stack *get_min_elem(t_stack *stack);
int find_mid_index(t_stack *stack_a);
t_stack *get_last_elem(t_stack *stack);
int calculate_weight(t_stack *elem_a, t_stack *stack_a,
                     t_stack *stack_b, int future_index);
void assign_weights(t_stack **stack_a, t_stack **stack_b);
int find_future_index_in_b(int num, t_stack *stack_b);
void	init_stack(t_stack *stack);

/***************moves***************/
void move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *stack_el);
void finalize_stack_a(t_stack **stack_a);
void move_min_to_top(int index, t_stack **stack);
void move_b_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *elem);
void move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *elem);

/***************sort***************/
void sort_three(t_stack **stack_a);
void sort(t_stack **stack_a, t_stack **stack_b);
#endif