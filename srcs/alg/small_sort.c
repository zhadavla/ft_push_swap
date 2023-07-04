/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:52:59 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/29 19:45:50 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* function to check if the stack is sorted,
if it is sorted then it returns 0, else 1*/
bool is_not_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->data > stack->next->data)
            return (true);
        stack = stack->next;
    }
    return (false);
}

/* function that sorts when there are only three  left in stack A */
void    sort_three(t_stack **stack_a)
{
    if (is_not_sorted(*stack_a))
    {
        if ((*stack_a)->data == find_min_value(*stack_a))
        {
            rra(stack_a);
            sa(stack_a);
        }
        else if ((*stack_a)->data == find_max_value(*stack_a))
        {
            ra(stack_a);
            if (is_not_sorted(*stack_a))
                sa(stack_a);
        }
        else
        {
            if (((*stack_a)->next->data) == find_min_value(*stack_a))
                sa(stack_a);
            else 
                rra(stack_a);
        }
    }
}
