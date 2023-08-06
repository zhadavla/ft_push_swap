/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:04:53 by vzhadan           #+#    #+#             */
/*   Updated: 2023/08/06 17:09:46 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * getting array of ints from the array of the char-representation of ints
 * @param argv array of char-represented numbers
 * @param len
 * @return ar
 */
int	*chars_to_ints(char **argv, int len)
{
	int	*ar;
	int	i;

	ar = (int *)malloc(sizeof(*ar) * len);
	i = 1;
	while (i < len)
	{
		ar[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (ar);
}

/**
 * converting array to linked-list stack
 * @param array
 * @param len
 * @param is_a
 * @return
 */
t_stack	*array_to_stack(const int *array, int len, BOOL is_a)
{
	t_stack	*top;
	int		i;
	t_stack	*new_element;

	top = NULL;
	i = len - 1;
	while (i >= 0)
	{
		new_element = (t_stack *)malloc(sizeof(t_stack));
		new_element->data = array[i];
		new_element->index = i;
		new_element->weight = -1;
		new_element->is_a = is_a;
		new_element->next = top;
		top = new_element;
		i--;
	}
	return (top);
}

int	*split_to_ints(char **str_splited, int len)
{
	int	*ar;
	int	i;

	ar = (int *)malloc(sizeof(*ar) * len);
	i = 0;
	while (i < len)
	{
		ar[i] = ft_atoi(str_splited[i]);
		i++;
	}
	return (ar);
}

t_stack	*get_input(int argc, char **argv)
{
	int		*array;
	char	**splitted;
	t_stack	*stack;
	int		len;

	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		len = 0;
		while (splitted[len])
			len++;
		array = split_to_ints(splitted, len);
	}
	else
		array = chars_to_ints(argv, argc);
	if (argc == 2)
		stack = array_to_stack(array, len, TRUE);
	else
		stack = array_to_stack(array, argc - 1, TRUE);
	free(array);
	return (stack);
}
