/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:56:46 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/07/06 21:23:45 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */

#include "../push_swap.h"

bool digit_check(char *str)
{
    int i;

    i = 0;
    if ((str[i] == '-' || str[i] == '+') && str[i+1] == '\0')
        return (true);
    while (str[i] != 0)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
            return (true);
        i++;
    }
    return (false);
}

int dup_check(int argc, char **str, int flag)
{
    int i;
    int j;
    
    if (flag == 2)  // if we pass 2, it means that we iterate through char **temp and should start from index 0
        i = 0;
    else if (flag == 1) // if we pass 1, it means that we iterate through char **argv and should start from index 1
        i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j != argc)
        {
            if ((ft_atoi(str[i]) == ft_atoi(str[j])))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int range_check(char *str)
{
    if (!(ft_atoi_long(str) >= -2147483648 && ft_atoi_long(str) <= 2147483647))
        return (1);
    return (0);
}
