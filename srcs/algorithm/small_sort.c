#include "../push_swap.h"

bool is_not_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->data > stack->next->data)
            return (true);
        stack = stack->next;
    }
    return (false);
}

void    sort_three(t_stack **stack_a)
{
    if (is_not_sorted(*stack_a))
    {
        if ((*stack_a)->data == find_min_value(*stack_a))
        {
            rra(stack_a);
            sa(stack_a);
        }
        else if ((*stack_a)->data == find_max_value(*stack_a))
        {
            ra(stack_a);
            if (is_not_sorted(*stack_a))
                sa(stack_a);
        }
        else
        {
            if ((*stack_a)->next->data == find_min_value(*stack_a))
                sa(stack_a);
            else 
                rra(stack_a);
        }
    }
}
