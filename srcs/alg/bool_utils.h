#ifndef PUSH_SWAP_BOOL_UTILS_H
#define PUSH_SWAP_BOOL_UTILS_H

#include "../push_swap.h"

t_stack *find_by_value(t_stack *stack, int value);

bool is_not_sorted(t_stack *stack);
void move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *stack_el);

bool in_first_a_second_b(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool in_second_a_first_b(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

#endif //PUSH_SWAP_BOOL_UTILS_H
