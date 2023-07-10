#include "libft.h"

/*
 *	 Adds the node ’new’ at the beginning of the list.
*/
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}