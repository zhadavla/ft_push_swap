#include   "../push_swap.h"

/* this function returns the index of the middle of the list, 
the result will be used to define in which direction rotation will happen */
int find_mid_index(t_stack *stack) {
    int size;

    size = ft_lstsize(stack);
    if (size % 2 == 0)
        return size / 2;
    return size / 2 + 1;
}

/* this function returns the last node of the list */
t_stack	*get_last_elem(t_stack *stack)
{
	t_stack	*x;

	x = stack;
	while (x->next != NULL)
		x = x->next;
	return (x);
}

/* this function get the before position where the elem should be */
int	get_index_before(t_stack *elem, t_stack *stack)
{
	int	pos_before;

	pos_before = 1;
	while (!((stack)->data > (elem)->data && (stack)->data < (elem)->next->data)
            && (elem)->next != NULL)
	{
		pos_before++;
		(elem) = (elem)->next;
	}
	return (pos_before);
}