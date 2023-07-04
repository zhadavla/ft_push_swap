/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_suboperations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:47:35 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/25 21:48:36 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*  do rr * weight_a and rb * (weight_b - weight_a)
	or
	do rr * weight_b and ra * (weight_a - weight_b) */
void	submove_rr(int weight_a, int weight_b, t_stack **stack_a, t_stack **stack_b)
{
		if (weight_a <= weight_b)
		{
			weight_b -= weight_a;
			while (weight_a-- != 0)
				rr(stack_a, stack_b);
			while (weight_b-- != 0)
				rb(stack_b);
		}
		else if (weight_b < weight_a)
		{
			weight_a -= weight_b;
			while (weight_b-- != 0)
				rr(stack_a, stack_b);
			while (weight_a-- != 0)
				ra(stack_a);
		}
}

/*  do rrr * weight_a and rrb * (weight_b - weight_a)
	or
	do rrr * weight_b and rra * (weight_a - weight_b) */
void	submove_rrr(int weight_a, int weight_b, t_stack **stack_a, t_stack **stack_b)
{
		if (weight_a <= weight_b)
		{
			weight_b -= weight_a;
			while (weight_a-- != 0)
				rrr(stack_a, stack_b);
			while (weight_b-- != 0)
				rrb(stack_b);
		}
		else if (weight_b < weight_a)
		{
			weight_a -= weight_b;
			while (weight_b-- != 0)
				rrr(stack_a, stack_b);
			while (weight_a-- != 0)
				rra(stack_a);
		}
}

/*	do ra * weight_a
	do rrb * weight_b */
void	submove_rarrb(int weight_a, int weight_b, t_stack **stack_a, t_stack **stack_b)
{
		while (weight_a-- != 0)
			ra(stack_a);
		while (weight_b-- != 0)
			rrb(stack_b);
}

/*	do rra * scora_a
	do rb * weight_b */
void	submove_rbrra(int weight_a, int weight_b, t_stack **stack_a, t_stack **stack_b)
{
		while (weight_a--)
			rra(stack_a);
		while (weight_b--)
			rb(stack_b);
}

/* this function pushes first 2 elem of stack A to stack B as a starting point for sorting.
And sorts stack_b in descending order if needed */
void pb_two_elem(t_stack **stack_a, t_stack **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		sb(stack_b);
}