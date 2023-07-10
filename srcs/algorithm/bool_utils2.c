/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:01:40 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:22:45 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

BOOL	in_first_half_a(t_stack *node, t_stack *stack_a)
{
	return (node->index < find_mid_index(stack_a));
}

BOOL	in_first_half_b(t_stack *stack_b, int index_in_b)
{
	return (index_in_b < find_mid_index(stack_b));
}
