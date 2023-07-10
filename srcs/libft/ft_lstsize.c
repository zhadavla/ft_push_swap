/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:02:57 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:02:58 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	t_stack	*x;
	int		counter;

	x = lst;
	counter = 0;
	while (x != NULL)
	{
		counter++;
		x = x->next;
	}
	return (counter);
}
