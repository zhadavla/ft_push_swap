#include "../push_swap.h"

void sb(t_stack **stack)
{
   stack_swap(stack, true);
}

void rb(t_stack **stack)
{
   rotate_stack(stack, true);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    stack_push_to(stack_a, stack_b);
}

void rrb(t_stack **stack)
{
    reverse_rotate_stack(stack, true);
}
