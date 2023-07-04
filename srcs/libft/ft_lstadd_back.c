/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:33:50 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/03 19:45:51 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*x;

	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	x = *lst;
	while (x->next != NULL)
	{
		x = x->next;
	}
	x->next = new;
	new->next = NULL;
}
