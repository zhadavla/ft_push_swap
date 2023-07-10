#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*x;

	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	x = *lst;
	while (x->next != NULL)
	{
		x = x->next;
	}
	x->next = new;
	new->next = NULL;
}
