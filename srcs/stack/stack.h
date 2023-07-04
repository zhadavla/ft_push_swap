#ifndef PUSH_SWAP_STACK_H
#define PUSH_SWAP_STACK_H
#include "../push_swap.h"


void stack_push_to(t_stack **stack_from, t_stack **stack_to);
void stack_push_a(t_stack **stack_a, t_stack **stack_b);
void reverse_rotate_stack(t_stack **stack, int needs_to_print);
void rotate_stack(t_stack **stack, int needs_to_print);
void stack_swap(t_stack **stack, int needs_to_print);
void stack_rotate_n_times(t_stack **stack, int n, bool print);
void stack_reverse_rotate_n_times(t_stack **stack, int n, bool print);
void rrr_n_times(t_stack **stack_a, t_stack **stack_b, int n);
void rr_n_times(t_stack **stack_a, t_stack **stack_b, int n);
void ss_n_times(t_stack **stack_a, t_stack **stack_b, int n);


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

// functions for stack suboperations
void	pb_two_elem(t_stack **stack_a, t_stack **stack_b);
void	submove_rbrra(int weight_a, int weight_b,
                      t_stack **stack_a, t_stack **stack_b);
void	submove_rarrb(int weight_a, int weight_b,
                      t_stack **stack_a, t_stack **stack_b);
void	submove_rrr(int weight_a, int weight_b,
                    t_stack **stack_a, t_stack **stack_b);
void	submove_rr(int weight_a, int weight_b,
                   t_stack **stack_a, t_stack **stack_b);

// function for additional stack operations
void	finalize_stack_a(t_stack **stack_a);
void	stack_rotation(int index, t_stack **stack);
void	move_b_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *elem);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *elem);
void	init_stack(t_stack *stack);

#endif //PUSH_SWAP_STACK_H
