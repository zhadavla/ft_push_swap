/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:58:40 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/08 17:53:23 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void init_stack(t_stack *stack)
{
    int i;

    i = 0; 
    while (stack != NULL)
    {
        stack->index = i;
        stack->weight = 0;
        stack = stack->next;
        i++;
    }
}

t_stack	*find_cheapest_elem(t_stack *stack)
{
	t_stack *cheapest_element;

	cheapest_element = stack;
	while (stack != NULL)
	{
		if (stack->weight == 1)
            return stack;
		if (stack->weight < cheapest_element->weight)
			cheapest_element = stack;
		stack = stack->next;
	}
	return (cheapest_element);
}

void pb_two_elem(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		sb(stack_b);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_element;
	
	if (!is_not_sorted(*stack_a))
		return ;

    if (ft_lstsize(*stack_a) > 3){
		pb_two_elem(stack_a, stack_b);
	}
    
	while (ft_lstsize(*stack_a) > 3)
	{		
		init_stack(*stack_a);
		init_stack(*stack_b);
		assign_weights(stack_a, stack_b);
		cheapest_element = find_cheapest_elem(*stack_a);
		move_a_to_b(stack_a, stack_b, cheapest_element);
	}

	if (is_not_sorted(*stack_a))
		sort_three(stack_a);

	while (ft_lstsize(*stack_b) != 0)
	{		
		init_stack(*stack_a);
		init_stack(*stack_b);
		assign_weights(stack_a, stack_b);
		cheapest_element = find_cheapest_elem(*stack_b);
		move_b_to_a(stack_b, stack_a, cheapest_element);
	}
	
	finalize_stack_a(stack_a);
}

