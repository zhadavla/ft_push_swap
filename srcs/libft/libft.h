# ifndef LIBFT_H
# define LIBFT_H

# include "../push_swap.h"
# include "../stack/stack.h"

int ft_atoi(const char *nptr);
long    ft_atoi_long(const char *nptr);
char    **ft_split(char const *s, char c);
size_t  ft_strlen(const char *s);
t_stack *ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);

# endif