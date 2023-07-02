#include "stack.h"

/**
 * performs swapping with two stacks simultaneously
 * @param stack_a
 * @param stack_b
 */
void ss(t_stack **stack_a, t_stack **stack_b) {
    stack_swap(stack_a, false);
    stack_swap(stack_b, false);
    write(1, "ss\n", 3);
}

/**
 * performs rotation with two stacks simultaneously
 * @param stack_a
 * @param stack_b
 */
void rr(t_stack **stack_a, t_stack **stack_b) {
    stack_rotate(stack_a, false);
    stack_rotate(stack_b, false);
    write(1, "rr\n", 3);
}

/**
 * performs reverse rotation with two stacks simultaneously
 * @param stack_a
 * @param stack_b
 */
void rrr(t_stack **stack_a, t_stack **stack_b) {
    stack_reverse_rotate(stack_a, false);
    stack_reverse_rotate(stack_b, false);
    write(1, "rrr\n", 4);
}
