/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:05:10 by vzhadan           #+#    #+#             */
/*   Updated: 2023/08/06 16:27:19 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (error(argc, argv))
		return (write(2, "Error\n", 6));
	stack_a = get_input(argc, argv);
	sort(&stack_a, &stack_b);
	ft_free(&stack_a, &stack_b);
	return (0);
}
