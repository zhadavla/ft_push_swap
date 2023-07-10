/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:04:16 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:15:28 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * performs swapping with two stacks simultaneously
 * @param stack_a
 * @param stack_b
 */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	stack_swap(stack_a, FALSE);
	stack_swap(stack_b, FALSE);
	write(1, "ss\n", 3);
}

/**
 * performs rotation with two stacks simultaneously
 * @param stack_a
 * @param stack_b
 */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, FALSE);
	rotate_stack(stack_b, FALSE);
	write(1, "rr\n", 3);
}

/**
 * performs reverse rotation with two stacks simultaneously
 * @param stack_a
 * @param stack_b
 */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a, FALSE);
	reverse_rotate_stack(stack_b, FALSE);
	write(1, "rrr\n", 4);
}
