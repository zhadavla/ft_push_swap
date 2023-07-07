#include "../push_swap.h"

void sa(t_stack **stack)
{
   stack_swap(stack, true);
}

void ra(t_stack **stack)
{
   rotate_stack(stack, true);
}

void rra(t_stack **stack)
{
   reverse_rotate_stack(stack, true);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    stack_push_to(stack_b, stack_a);
}
