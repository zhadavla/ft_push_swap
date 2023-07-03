#include "ft_algorithm.h"

t_stack *find_max_node(t_stack *stack) {
    int max_value;
    t_stack *max_node;

    max_value = find_max_value(stack);
    max_node = find_by_value(stack, max_value);
    return max_node;
}

int find_min_value(t_stack *stack) {
    int min_value;

    min_value = stack->data;
    while (stack) {
        if (min_value > stack->data)
            min_value = stack->data;
        stack = stack->next;
    }
    return min_value;
}

int find_max_value(t_stack *stack) {
    int max_value;

    max_value = stack->data;
    while (stack) {
        if (max_value < stack->data)
            max_value = stack->data;
        stack = stack->next;
    }
    return max_value;
}

t_stack *find_by_value(t_stack *stack, int value) {
    while (stack) {
        if (value == stack->data)
            return stack;
        stack = stack->next;
    }
    return NULL;
}

