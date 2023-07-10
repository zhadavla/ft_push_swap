/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:02:08 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:30:05 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_weights(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		future_index;

	node = *stack_a;
	while (node != NULL)
	{
		future_index = find_future_index_in_b(node->data, *stack_b);
		node->weight = calculate_weight(node, *stack_a, *stack_b, future_index);
		if (node->weight == 1)
			return ;
		node = node->next;
	}
}

int	calculate_weight(t_stack *elem_a, t_stack *stack_a, t_stack *stack_b,
		int future_index)
{
	int	weight_a;
	int	weight_b;

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
	if (can_rotate_both(elem_a, stack_a, stack_b, future_index) && weight_a != 0
		&& weight_b != 0)
	{
		if (weight_a <= weight_b)
			weight_a = 0;
		else
			weight_b = 0;
	}
	return (weight_a + weight_b + 1);
}
