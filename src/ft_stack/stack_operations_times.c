#include "stack.h"
// functions to perform operations many times

void stack_rotate_n_times(t_stack **stack, int n, bool print) {
    while (n-- != 0)
        stack_rotate(stack, print);
}

void stack_reverse_rotate_n_times(t_stack **stack, int n, bool print) {
    while (n-- != 0)
        stack_reverse_rotate(stack, print);
}

void rrr_n_times(t_stack **stack_a, t_stack **stack_b, int n) {
    while (n-- != 0)
        rrr(stack_a, stack_b);
}

void rr_n_times(t_stack **stack_a, t_stack **stack_b, int n) {
    while (n-- != 0)
        rr(stack_a, stack_b);
}

void ss_n_times(t_stack **stack_a, t_stack **stack_b, int n) {
    while (n-- != 0)
        ss(stack_a, stack_b);
}

