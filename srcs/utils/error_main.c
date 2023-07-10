#include "../push_swap.h"

int temp_error(char **temp)
{
    int i;
    int size;
    
    i = 0;
    size = 0;
    while (temp[size] != 0)
        size++;
    while (temp[i] != 0)
    {
        if (digit_check(temp[i]) || range_check(temp[i]))
            return (true);
        i++;
    }
    if (duplicite_check(size, temp, 2))
        return (true);
    return (false);
}

int is_argv_error(int argc, char **argv)
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        if (digit_check(argv[i]) == 1 || range_check(argv[i]) == 1)
            return (true);
        i++;
    }
    if (duplicite_check(argc, argv, 1) == 1)
        return (true);
    return (false);
}

bool error(int argc, char **argv)
{
    char **temp;
    bool is_error;
    
    
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
