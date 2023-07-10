/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:04:23 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:15:15 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack)
{
	stack_swap(stack, TRUE);
}

void	ra(t_stack **stack)
{
	rotate_stack(stack, TRUE);
}

void	rra(t_stack **stack)
{
	reverse_rotate_stack(stack, TRUE);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_to(stack_b, stack_a);
}
