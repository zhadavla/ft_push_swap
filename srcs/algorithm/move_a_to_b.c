/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:01:45 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:15:28 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_future_index_in_b(int value, t_stack *stack_b)
{
	int	future_index;

	if (value < find_min_value(stack_b) || value > find_max_value(stack_b))
		return (get_max_elem(stack_b)->index);
	if ((stack_b->is_a == FALSE && value < get_last_elem(stack_b)->data
			&& value > stack_b->data))
		return (0);
	future_index = 1;
	while (stack_b->next != NULL && !(value < stack_b->data
			&& value > stack_b->next->data))
	{
		future_index++;
		stack_b = stack_b->next;
	}
	return (future_index);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *elem)
{
	int	weight_a;
	int	weight_b;
	int	future_index;

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
