/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper_adds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:25:18 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/18 21:36:56 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* based on the input, this funtion decides 
which direction to use for rotation of the stack ra or rra */
void	stack_rotation(int index, t_stack **stack)
{
	if (index >= find_mid_index(*stack))
	{
		index = ft_lstsize(*stack) - index;
		while (index-- != 0)
			rra(stack);
	}
	else if (index < find_mid_index(*stack))
	{
		while (index-- != 0)
			ra(stack);
	}
}

/* this function rotates (or reverse rotates) 
stack_a until the min value is on top */
void	finalize_stack_a(t_stack **stack_a)
{
	int		index;
	int		min;
	t_stack	*elem;

	elem = *stack_a;
	min = find_min_value(*stack_a);
	if ((*stack_a)->data == min)
		return ;
	index = 0;
	while ((elem)->data != min)
	{
		index++;
		elem = (elem)->next;
	}
	stack_rotation(index, stack_a);
}
