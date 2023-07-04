/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:53:54 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 22:05:25 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* this function gets the future index of the elem in another stack in order to calculated the weight */
int	get_future_index_in_b(int num, t_stack *stack_b)
{
	int future_index;

	if (num < find_min_value(stack_b) || num > find_max_value(stack_b))
        return get_max_elem(stack_b)->index;

    if (num < get_last_elem(stack_b)->data && num > stack_b->data)
        return 0;

    future_index = 1;
    while (stack_b->next != NULL
        && !(num < stack_b->data && num > stack_b->next->data))
    {
        future_index++;
        stack_b = stack_b->next;
    }
	return (future_index);
}
//
///* this function assigns the weight value to each of the node->weight */
void assign_weights(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node;
	int future_index;

	node = *stack_a;
	while (node != NULL)
	{
		future_index = get_future_index_in_b(node->data, *stack_b);
		node->weight = calculate_weight(node, *stack_a, *stack_b, future_index);
		if (node->weight == 1)
            return;
		node = node->next;
	}
}

void move_second_a_first_b(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_first_a_second_b(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_second_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
void move_from_a_to_b_first_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b);
#include "bool_utils.h"

void move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *stack_el) {
    int weight_a;
    int weight_b;
    int index_in_b;

    weight_a = 0;
	weight_b = 0;
    index_in_b = get_future_index_in_b(stack_el->data, *stack_b);
	if (stack_el->index < find_mid_index(*stack_a))
		weight_a += stack_el->index;
	else
		weight_a += ft_lstsize(*stack_a) - stack_el->index;
	if (index_in_b < find_mid_index(*stack_b))
		weight_b += index_in_b;
	else
		weight_b += ft_lstsize(*stack_b) - index_in_b;
    if (in_first_half_both(stack_el, *stack_a, *stack_b, index_in_b))
        move_from_a_to_b_first_half(stack_a, stack_b, weight_a, weight_b);
    else if (in_second_half_both(stack_el, *stack_a, *stack_b, index_in_b))
        move_second_half(stack_a, stack_b, weight_a, weight_b);
    else if (in_first_a_second_b(stack_el, *stack_a, *stack_b, index_in_b))
        move_first_a_second_b(stack_a, stack_b, weight_a, weight_b);
    else if (in_second_a_first_b(stack_el, *stack_a, *stack_b, index_in_b))
        move_second_a_first_b(stack_a, stack_b, weight_a, weight_b);
    stack_push_to(stack_a, stack_b);
}

        void move_first_a_second_b(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    while (weight_a-- != 0)
        rotate_stack(stack_a, true);
    while (weight_b-- != 0)
        reverse_rotate_stack(stack_b, true);
}

void move_second_a_first_b(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    while (weight_a--)
        reverse_rotate_stack(stack_a, true);
    while (weight_b--)
        rotate_stack(stack_b, true);
}

void move_second_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    if (weight_a <= weight_b) {
        weight_b -= weight_a;
        while (weight_a-- != 0)
            rrr(stack_a, stack_b);
        while (weight_b-- != 0)
            reverse_rotate_stack(stack_b, true);
    } else if (weight_b < weight_a) {
        weight_a -= weight_b;
        while (weight_b-- != 0)
            rrr(stack_a, stack_b);
        while (weight_a-- != 0)
            reverse_rotate_stack(stack_a, true);
    }
}

void move_from_a_to_b_first_half(t_stack **stack_a, t_stack **stack_b, int weight_a, int weight_b) {
    if (weight_a <= weight_b) {
        weight_b -= weight_a;
        while (weight_a-- != 0)
            rr(stack_a, stack_b);
        while (weight_b-- != 0)
            rotate_stack(stack_b, true);
    } else if (weight_b < weight_a) {
        weight_a -= weight_b;
        while (weight_b-- != 0)
            rr(stack_a, stack_b);
        while (weight_a-- != 0)
            rotate_stack(stack_a, true);
    }

}
