/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:59:28 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/04 17:05:35 by vlad             ###   ########.fr       */
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


void sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_element;
	if (!is_not_sorted(*stack_a))
		return ;
	// 1. move from A to B;
    pb_two_elem(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{		
		init_stack(*stack_a);
		init_stack(*stack_b);
		assign_weights(stack_a, stack_b);
		cheapest_element = find_cheapest_elem(*stack_a);
		move_a_to_b(stack_a, stack_b, cheapest_element);
	}

	// 2.sort three A
	if (is_not_sorted(*stack_a))	// printf("{cheapest_element: %d, %d}", cheapest_element->data, cheapest_element->weight);
		sort_three(stack_a);

	// 3. Move from B to A
	while (ft_lstsize(*stack_b) != 0)
	{		
		init_stack(*stack_a);
		init_stack(*stack_b);
		get_weight_ba(stack_a, stack_b);
		cheapest_element = find_cheapest_elem(*stack_b);
		move_b_to_a(stack_b, stack_a, cheapest_element);
	}
	
	// 4. Rotate A until sorted
	finalize_stack_a(stack_a);
}

