/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:04:35 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:15:15 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack **stack)
{
	stack_swap(stack, TRUE);
}

void	rb(t_stack **stack)
{
	rotate_stack(stack, TRUE);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_to(stack_a, stack_b);
}

void	rrb(t_stack **stack)
{
	reverse_rotate_stack(stack, TRUE);
}
