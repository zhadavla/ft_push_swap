/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:22:47 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/16 20:04:19 by mnurlybe         ###   ########.fr       */
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
