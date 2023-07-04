
#include "../push_swap.h"

int     calculate_weight(t_stack *elem_a, t_stack *stack_a, t_stack *stack_b, int future_index)
{
	int weight_a;
	int weight_b;

	weight_a = 0;
	weight_b = 0;
	if (elem_a->index < find_mid_index(stack_a))
		weight_a += elem_a->index;
	else
		weight_a += ft_lstsize(stack_a) - elem_a->index;
	if (future_index < find_mid_index(stack_b))
		weight_b += future_index;
	else
		weight_b += ft_lstsize(stack_b) - future_index;
	if (((elem_a->index < find_mid_index(stack_a) && future_index < find_mid_index(stack_b))
			|| (elem_a->index >= find_mid_index(stack_a) && future_index >= find_mid_index(stack_b)))
			&& weight_a != 0 && weight_b != 0)
		{
			if (weight_a <= weight_b)
				weight_a = 0;
			else if (weight_b < weight_a)
				weight_b = 0;
		}
	return (weight_a + weight_b + 1);
}