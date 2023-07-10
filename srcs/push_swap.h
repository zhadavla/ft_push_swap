#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define bool int
#define true 1
#define false 0

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "libft/libft.h"
#include "stack/stack.h"
#include "algorithm//algorithm.h"
#include <unistd.h>


t_stack *get_input(int argc, char **argv);

// functions to check the errors
bool error(int argc, char **argv);
bool digit_check(char *lst);
bool duplicite_check(int argc, char **lst, int flag);
int range_check(char *lst);

// functions to free memory
void free_stack(t_stack **stack);
void ft_free_arr(char **arr);
void ft_free(t_stack **stack_a, t_stack **stack_b);

#endif // PUSH_SWAP_PUSH_SWAP_H