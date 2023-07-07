#include "../push_swap.h"

int find_max_value(t_stack *stack) {
    int max;

    max = stack->data;
    while (stack != NULL) {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return (max);
}

int find_min_value(t_stack *stack) {
    int min;


    min = stack->data;
    while (stack != NULL) {
        if (stack->data < min)
            min = stack->data;
        stack = stack->next;
    }
    return (min);
}

t_stack *get_max_elem(t_stack *stack) {
    return find_by_value(stack, find_max_value(stack));
}

t_stack *get_min_elem(t_stack *stack) {
    return find_by_value(stack, find_min_value(stack));
}

int	find_future_index_in_b(int value, t_stack *stack_b)
{
    int future_index;
    
    if (value < find_min_value(stack_b) || value > find_max_value(stack_b))
        return get_max_elem(stack_b)->index;

    if ((stack_b->is_a == false && value < get_last_elem(stack_b)->data && value > stack_b->data))
        return 0;

    future_index = 1;
    while (stack_b->next != NULL
           && !(value < stack_b->data && value > stack_b->next->data))
    {
        future_index++;
        stack_b = stack_b->next;
    }
    return (future_index);
}