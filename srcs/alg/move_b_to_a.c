/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:47:42 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 22:07:33 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "../push_swap.h"

/* this function gets the future index of the elem in another stack in order to calculated the weight */
int	get_future_index_in_a(int num, t_stack *stack_a)
{
	int future_index;

	if (num < find_min_value(stack_a) || num > find_max_value(stack_a))
		future_index = get_min_elem(stack_a)->index;
	else
	{
		future_index = 1;
		if (num > get_last_elem(stack_a)->data && num < stack_a->data)
			future_index = 0;
		else
		{
			while (stack_a->next != NULL && !(num > stack_a->data && num < stack_a->next->data))
			{
				future_index++;
				stack_a = stack_a->next; 
			}
		}
	}
	return (future_index);
}

/* this function assigns the weight value to each of the node->weight */
void get_weight_ba(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *elem;
	int future_index;

	elem = *stack_b;
	while (elem != NULL)
	{
		future_index = get_future_index_in_a(elem->data, *stack_a);
		elem->weight = calculate_weight(elem, *stack_b, *stack_a, future_index);
		if (elem->weight == 1)
			break ;
		elem = elem->next;
	}
}

void	move_b_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *elem)
{
	int weight_a;
	int weight_b;
	int future_index;

	weight_a = 0;
	weight_b = 0;
	future_index = get_future_index_in_a(elem->data, *stack_a);
	if (elem->index < find_mid_index(*stack_b))
		weight_b += elem->index;
	else
		weight_b += ft_lstsize(*stack_b) - elem->index;
	if (future_index < find_mid_index(*stack_a))
		weight_a += future_index;
	else 
		weight_a += ft_lstsize(*stack_a) - future_index;
	if (elem->index < find_mid_index(*stack_b) && future_index < find_mid_index(*stack_a))
		submove_rr(weight_a, weight_b, stack_a, stack_b);
	else if (elem->index >= find_mid_index(*stack_b) && future_index >= find_mid_index(*stack_a))
		submove_rrr(weight_a, weight_b, stack_a, stack_b);
	else if (elem->index < find_mid_index(*stack_b) && future_index >= find_mid_index(*stack_a))
		submove_rbrra(weight_a, weight_b, stack_a, stack_b);
	else if (elem->index >= find_mid_index(*stack_b) && future_index < find_mid_index(*stack_a))
		submove_rarrb(weight_a, weight_b, stack_a, stack_b);
	pa(stack_a, stack_b);
}

