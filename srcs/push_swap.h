/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:05:13 by vzhadan           #+#    #+#             */
/*   Updated: 2023/07/10 14:28:24 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BOOL int
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	unsigned int	weight;
	struct s_stack	*next;
	BOOL			is_a;
}					t_stack;

/***********************libft***********************/
int					ft_atoi(const char *nptr);
long				ft_atoi_long(const char *nptr);
char				**ft_split(char const *s, char c);
int					ft_strlen(const char *s);
t_stack				*ft_lstnew(int data);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);

/***********************stack***********************/
void				stack_push_to(t_stack **stack_from, t_stack **stack_to);
void				reverse_rotate_stack(t_stack **stack, int needs_to_print);
void				rotate_stack(t_stack **stack, int needs_to_print);
void				stack_swap(t_stack **stack, int needs_to_print);
void				move_min_to_top_n_times(t_stack **stack, int n, BOOL print);
void				stack_reverse_rotate_n_times(t_stack **stack, int n,
						BOOL print);

/***********************subject stack operations***********************/
void				sa(t_stack **stack);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack);
void				rra(t_stack **stack);
void				sb(t_stack **stack);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				rb(t_stack **stack);
void				rrb(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

/***************BOOL utilits***************/
BOOL				in_first_half_a(t_stack *node, t_stack *stack_a);
BOOL				in_first_half_b(t_stack *stack_b, int index_in_b);
BOOL				in_first_second(t_stack *node, t_stack *stack_a,
						t_stack *stack_b, int index_in_b);
BOOL				in_second_first(t_stack *node, t_stack *stack_a,
						t_stack *stack_b, int index_in_b);
BOOL				in_first_half_both(t_stack *node, t_stack *stack_a,
						t_stack *stack_b, int index_in_b);
BOOL				in_second_half_both(t_stack *node, t_stack *stack_a,
						t_stack *stack_b, int index_in_b);
BOOL				can_rotate_both(t_stack *node, t_stack *stack_a,
						t_stack *stack_b, int index_in_b);

/***************move utilits***************/
void				move_first_second(t_stack **stack_a, t_stack **stack_b,
						int weight_a, int weight_b);
void				move_second_first(t_stack **stack_a, t_stack **stack_b,
						int weight_a, int weight_b);
void				move_second_half(t_stack **stack_a, t_stack **stack_b,
						int weight_a, int weight_b);
void				move_first_half(t_stack **stack_a, t_stack **stack_b,
						int weight_a, int weight_b);

/***************sort utilits***************/
BOOL				is_not_sorted(t_stack *stack);
t_stack				*find_by_value(t_stack *stack, int value);
int					find_max_value(t_stack *stack);
int					find_min_value(t_stack *stack);
t_stack				*get_max_elem(t_stack *stack);
t_stack				*get_min_elem(t_stack *stack);
int					find_mid_index(t_stack *stack_a);
t_stack				*get_last_elem(t_stack *stack);
int					calculate_weight(t_stack *elem_a, t_stack *stack_a,
						t_stack *stack_b, int future_index);
void				assign_weights(t_stack **stack_a, t_stack **stack_b);
int					find_future_index_in_b(int num, t_stack *stack_b);
void				init_stack(t_stack *stack);

/***************moves***************/
void				move_a_to_b(t_stack **stack_a, t_stack **stack_b,
						t_stack *stack_el);
void				finalize_stack_a(t_stack **stack_a);
void				move_min_to_top(int index, t_stack **stack);
void				move_b_to_a(t_stack **stack_b, t_stack **stack_a,
						t_stack *elem);
void				move_a_to_b(t_stack **stack_a, t_stack **stack_b,
						t_stack *elem);

/***************sort***************/
void				sort_three(t_stack **stack_a);
void				sort(t_stack **stack_a, t_stack **stack_b);

t_stack				*get_input(int argc, char **argv);

// functions to check the errors
BOOL				error(int argc, char **argv);
BOOL				digit_check(char *lst);
BOOL				duplicite_check(int argc, char **lst, int flag);
int					range_check(char *lst);

// functions to free memory
void				free_stack(t_stack **stack);
void				ft_free_arr(char **arr);
void				ft_free(t_stack **stack_a, t_stack **stack_b);

#endif // PUSH_SWAP_PUSH_SWAP_H