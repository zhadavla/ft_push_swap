/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:32:37 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 20:36:53 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_arr(char **arr)
{
    char *str;

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

void    ft_free_list(t_stack **stack)
{
    t_stack *el;

    if (!stack)
        return ;
    while (*stack)
    {
        el = (*stack)->next;
        (*stack)->data = 0;
        free(*stack);
        *stack = el;
    }
}

void    ft_free(t_stack **stack_a, t_stack **stack_b)
{
    ft_free_list(stack_a);
    ft_free_list(stack_b);
}
