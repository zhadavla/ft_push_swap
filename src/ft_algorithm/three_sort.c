#include "ft_algorithm.h"

bool is_not_sorted(t_stack *stack) {
    t_stack *elem;

    elem = stack;
    while (elem->next) {
        if (elem->data > elem->next->data)
            return (true);
        elem = elem->next;
    }
    return (false);
}

void sort_three_element_stack(t_stack **stack_a) {
    if (is_not_sorted(*stack_a)) {
        // 1 3 2
        if ((*stack_a)->data == find_min_value(*stack_a)) {
            reverse_rotate_stack(stack_a, true);
            stack_swap(stack_a, true);
            // 3 1 2
        } else if ((*stack_a)->data == find_max_value(*stack_a)) {
            rotate_stack(stack_a, true);
            if (is_not_sorted(*stack_a))
                stack_swap(stack_a, true);
        } else {
            if (((*stack_a)->next->data) == find_min_value(*stack_a))
                stack_swap(stack_a, true);
            else
                reverse_rotate_stack(stack_a, true);
        }
    }
}