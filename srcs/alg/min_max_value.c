/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:19:15 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 21:51:40 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_max_value(t_stack *stack) {
    int max;

    max = stack->data;
    while (stack != NULL) {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return (max);
}

int find_min_value(t_stack *stack) {
    int min;

    min = stack->data;
    while (stack != NULL) {
        if (stack->data < min)
            min = stack->data;
        stack = stack->next;
    }
    return (min);
}

/**
 * @return stack node with the specific value
 */
t_stack *find_by_value(t_stack *stack, int value) {
    while (stack && stack->data != value)
        stack = stack->next;
    return stack;
}

t_stack *get_max_elem(t_stack *stack) {
    return find_by_value(stack, find_max_value(stack));
}

t_stack *get_min_elem(t_stack *stack) {
    return find_by_value(stack, find_min_value(stack));
}