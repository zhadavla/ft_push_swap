

#ifndef PUSH_SWAP_ALGORITHM_H
#define PUSH_SWAP_ALGORITHM_H

#include "../push_swap.h"

t_stack *find_by_value(t_stack *stack, int value);

void move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *stack_el);
bool is_not_sorted(t_stack *stack);
t_stack *find_by_value(t_stack *stack, int value);

/***************bool utilits***************/
bool    in_first_half_a(t_stack *node, t_stack *stack_a) ;
bool    in_first_half_b(t_stack *stack_b, int index_in_b);
bool    in_first_second(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool    in_second_first(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool    in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool    in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);
bool    can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool tmpBool(int value, t_stack *stack_b);

/***************move utilits***************/
void move_first_second(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_second_first(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_second_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_first_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);




int	find_future_index_in_b(int value, t_stack *stack_b);
#endif // PUSH_SWAP_ALGORITHM_H
