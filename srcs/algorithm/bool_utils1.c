/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:01:43 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:24:38 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

BOOL	in_second_first(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (!in_first_half_a(node, stack_a) && in_first_half_b(stack_b,
			index_in_b));
}

BOOL	in_first_second(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (in_first_half_a(node, stack_a) && !in_first_half_b(stack_b,
			index_in_b));
}

BOOL	in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (in_first_half_a(node, stack_a) && in_first_half_b(stack_b,
			index_in_b));
}

BOOL	in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (!in_first_half_a(node, stack_a) && !in_first_half_b(stack_b,
			index_in_b));
}

BOOL	can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b,
		int index_in_b)
{
	return (in_first_half_both(node, stack_a, stack_b, index_in_b)
		|| in_second_half_both(node, stack_a, stack_b, index_in_b));
}
