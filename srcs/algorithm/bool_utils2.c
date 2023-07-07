#include "../push_swap.h"

bool in_first_half_a(t_stack *node, t_stack *stack_a) {
    return node->index < find_mid_index(stack_a);
}

bool in_first_half_b(t_stack *stack_b, int index_in_b) {
    return index_in_b < find_mid_index(stack_b);
}