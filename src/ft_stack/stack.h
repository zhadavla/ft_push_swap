#ifndef PUSH_SWAP_STACK_H
#define PUSH_SWAP_STACK_H

#include "../push_swap.h"

typedef struct s_stack {
    int data;
    int is_a;
    int index; // index of element in the stack
    int score; // how long does it take to transfer this element to stack b
    struct s_stack *next;
} t_stack;

// utils
int ft_lstsize(t_stack *lst);
void print_stacks(t_stack *a, t_stack *b);
t_stack *array_to_stack(const int *array, int length, bool is_a);
void ft_lstadd_back(t_stack **lst, t_stack *new);
void ft_lstadd_front(t_stack **lst, t_stack *new);
void execute_command(t_stack *stack_a, t_stack *stack_b);

// operations
void stack_push_to(t_stack **stack_from, t_stack **stack_to);
void stack_push_a(t_stack **stack_a, t_stack **stack_b);
void stack_reverse_rotate(t_stack **stack, int needs_to_print);
void stack_rotate(t_stack **stack, int needs_to_print);
void stack_swap(t_stack **stack, int needs_to_print);

void ss(t_stack **stack_a, t_stack **stack_b);

void rr(t_stack **stack_a, t_stack **stack_b);

void rrr(t_stack **stack_a, t_stack **stack_b);

void stack_rotate_n_times(t_stack **stack, int n, bool print);

void stack_reverse_rotate_n_times(t_stack **stack, int n, bool print);

void rrr_n_times(t_stack **stack_a, t_stack **stack_b, int n);

void rr_n_times(t_stack **stack_a, t_stack **stack_b, int n);

void ss_n_times(t_stack **stack_a, t_stack **stack_b, int n);


#endif //PUSH_SWAP_STACK_H
