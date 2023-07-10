/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:02:38 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:02:39 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_mid_index(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size % 2 == 0)
		return (size / 2);
	return (size / 2 + 1);
}

t_stack	*get_last_elem(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*find_by_value(t_stack *stack, int value)
{
	while (stack && stack->data != value)
		stack = stack->next;
	return (stack);
}
