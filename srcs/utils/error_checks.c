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

bool duplicite_check(int argc, char **str, int flag)
{
    int i;
    int j;
    
    if (flag == 2) 
        i = 0;
    else if (flag == 1)
        i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j != argc)
        {
            if ((ft_atoi(str[i]) == ft_atoi(str[j])))
                return (true);
            j++;
        }
        i++;
    }
    return (false);
}

int range_check(char *str)
{
    if (!(ft_atoi_long(str) >= -2147483648 && ft_atoi_long(str) <= 2147483647))
        return (1);
    return (0);
}
