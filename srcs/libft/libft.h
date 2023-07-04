#pragma once

#include "../push_swap.h"

typedef struct s_stack
{
    int				data;
    int				index;
    unsigned int	weight;
    struct s_stack	*next;
    bool			is_a;
}	t_stack;

int ft_atoi(const char *nptr);
long ft_atoi_long(const char *nptr);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);

