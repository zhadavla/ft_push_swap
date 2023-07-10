#ifndef STACK_H
#define STACK_H

typedef struct s_stack
{
    int				data;
    int				index;
    unsigned int	weight;
    struct s_stack	*next;
    bool			is_a;
}	t_stack;


#include "../push_swap.h"
#include "../libft/libft.h"

void stack_push_to(t_stack **stack_from, t_stack **stack_to);
void reverse_rotate_stack(t_stack **stack, int needs_to_print);
void rotate_stack(t_stack **stack, int needs_to_print);
void stack_swap(t_stack **stack, int needs_to_print);
void move_min_to_top_n_times(t_stack **stack, int n, bool print);
void stack_reverse_rotate_n_times(t_stack **stack, int n, bool print);

/***********************subject stack operations***********************/
void	sa(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sb(t_stack **stack);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif