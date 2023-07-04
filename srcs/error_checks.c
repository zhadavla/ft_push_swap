/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:56:46 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/01 16:00:07 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */

#include "push_swap.h"

int digit_check(char *lst)
{
    int i;

    i = 0;
    while (lst[i] != 0)
    {
        if (!((lst[i] >= '0' && lst[i] <= '9') || lst[i] == '-' || lst[i] == '+'))
            return (1);
        if (i == 0)
        {
            if ((lst[i] == '-' || lst[i] == '+') && lst[i+1] == '\0')
                return (1);
        }
        i++;
    }
    return (0);
}

int dup_check(int argc, char **lst, int flag)
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
            if ((ft_atoi(lst[i]) == ft_atoi(lst[j])))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int range_check(char *lst)
{
    if (!(ft_atoi_long(lst) >= -2147483648 && ft_atoi_long(lst) <= 2147483647))
        return (1);
    return (0);
}
