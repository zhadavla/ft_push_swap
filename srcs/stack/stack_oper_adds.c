#include "../push_swap.h"

void	move_min_to_top(int index, t_stack **stack)
{
	if (index >= find_mid_index(*stack))
	{
		index = ft_lstsize(*stack) - index;
		while (index-- != 0)
			rra(stack);
		return;
	}
	while (index-- != 0)
		ra(stack);
}

// rotates stack_a until the min value is on top 
void	finalize_stack_a(t_stack **stack_a)
{
	int		index;
	int		min;
	t_stack	*node;

	node = *stack_a;
	min = find_min_value(*stack_a);
	if ((*stack_a)->data == min)
		return ;
	index = 0;
	while ((node)->data != min)
	{
		index++;
		node = (node)->next;
	}
	move_min_to_top(index, stack_a);
}
