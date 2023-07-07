#include   "../push_swap.h"

int find_mid_index(t_stack *stack) {
    int size;

    size = ft_lstsize(stack);
    if (size % 2 == 0)
        return size / 2;
    return size / 2 + 1;
}

t_stack	*get_last_elem(t_stack *stack)
{
	while (stack->next != NULL)
        stack = stack->next;
	return (stack);
}

t_stack *find_by_value(t_stack *stack, int value) {
    while (stack && stack->data != value)
        stack = stack->next;
    return stack;
}
