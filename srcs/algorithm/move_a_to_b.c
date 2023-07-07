#include "../push_swap.h"

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *elem)
{
	int weight_a;
	int weight_b;
	int future_index;

	weight_a = 0;
	weight_b = 0;
	future_index = find_future_index_in_b(elem->data, *stack_b);
	if (elem->index < find_mid_index(*stack_a))
		weight_a += elem->index;
	else
		weight_a += ft_lstsize(*stack_a) - elem->index; 
	if (future_index < find_mid_index(*stack_b))
		weight_b += future_index;
	else 
		weight_b += ft_lstsize(*stack_b) - future_index;
	
	if (in_first_half_both(elem, *stack_a, *stack_b, future_index))
		move_first_half(stack_a, stack_b, weight_a, weight_b);
	else if (in_second_half_both(elem, *stack_a, *stack_b, future_index))
		move_second_half(stack_a, stack_b, weight_a, weight_b);
	else if (in_first_second(elem, *stack_a, *stack_b, future_index))
		move_first_second(stack_a, stack_b, weight_a, weight_b);
	else if (in_second_first(elem, *stack_a, *stack_b, future_index))
		move_second_first(stack_a, stack_b, weight_a, weight_b);
	pb(stack_a, stack_b);
}


void move_first_second(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    while (weight_a-- != 0)
        ra(stack_a);
    while (weight_b-- != 0)
		rrb(stack_b);
}

void move_second_first(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    while (weight_a--)
        reverse_rotate_stack(stack_a, true);
    while (weight_b--)
        rotate_stack(stack_b, true);
}

void move_second_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    if (weight_a <= weight_b) {
        weight_b -= weight_a;
        while (weight_a-- != 0)
            rrr(stack_a, stack_b);
        while (weight_b-- != 0)
            reverse_rotate_stack(stack_b, true);
    } else if (weight_b < weight_a) {
        weight_a -= weight_b;
        while (weight_b-- != 0)
            rrr(stack_a, stack_b);
        while (weight_a-- != 0)
            reverse_rotate_stack(stack_a, true);
    }
}

void move_first_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) 
{
    	if (weight_a <= weight_b)
		{
			weight_b -= weight_a;
			while (weight_a-- != 0)
				rr(stack_a, stack_b);
			while (weight_b-- != 0)
                rb(stack_b);
		}
		else
		{
			weight_a -= weight_b;
			while (weight_b-- != 0)
				rr(stack_a, stack_b);
			while (weight_a-- != 0)
                ra(stack_a);
		}

}
