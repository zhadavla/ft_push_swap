#include "../ft_algorithm/ft_algorithm.h"

bool in_first_half_a(t_stack *node, t_stack *stack_a) {
    return node->index < find_mid_index(stack_a);
}

bool in_first_half_b(t_stack *stack_b, int index_in_b) {
    return index_in_b < find_mid_index(stack_b);
}

bool in_second_a_first_b(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b) {
    return !in_first_half_a(node, stack_a) && in_first_half_b(stack_b, index_in_b);
}

bool in_first_a_second_b(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b) {
    return in_first_half_a(node, stack_a) && !in_first_half_b(stack_b, index_in_b);
}

bool in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b) {
    return in_first_half_a(node, stack_a) && in_first_half_b(stack_b, index_in_b);
}

bool in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b) {
    return !in_first_half_a(node, stack_a) && !in_first_half_b(stack_b, index_in_b);
}

bool can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b) {
    return in_first_half_both(node, stack_a, stack_b, index_in_b)
           || in_second_half_both(node, stack_a, stack_b, index_in_b);
}