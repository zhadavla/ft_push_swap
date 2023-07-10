/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:05:03 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:15:28 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	temp_error(char **temp)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (temp[size] != 0)
		size++;
	while (temp[i] != 0)
	{
		if (digit_check(temp[i]) || range_check(temp[i]))
			return (TRUE);
		i++;
	}
	if (duplicite_check(size, temp, 2))
		return (TRUE);
	return (FALSE);
}

int	is_argv_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) == 1 || range_check(argv[i]) == 1)
			return (TRUE);
		i++;
	}
	if (duplicite_check(argc, argv, 1) == 1)
		return (TRUE);
	return (FALSE);
}

BOOL	error(int argc, char **argv)
{
	char	**temp;
	BOOL	is_error;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		is_error = temp_error(temp);
		ft_free_arr(temp);
		free(temp);
		return (is_error);
	}
	else
		return (is_argv_error(argc, argv));
}
