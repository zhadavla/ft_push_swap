#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	t_stack	*x;
	int		counter;

	x = lst;
	counter = 0;
	while (x != NULL)
	{
		counter++;
		x = x->next;
	}
	return (counter);
}
