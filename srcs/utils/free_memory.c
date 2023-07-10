/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:05:00 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:05:01 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_arr(char **arr)
{
	char	*str;

	if (!arr)
		return ;
	while (*arr)
	{
		str = *arr;
		arr++;
		free(str);
	}
	*arr = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*node;

	if (!stack)
		return ;
	while (*stack)
	{
		node = (*stack)->next;
		(*stack)->data = 0;
		free(*stack);
		*stack = node;
	}
}

void	ft_free(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
