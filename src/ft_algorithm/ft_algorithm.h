#ifndef FT_PUSH_SWAP_FT_ALGORITHM_H
#define FT_PUSH_SWAP_FT_ALGORITHM_H





/**
 * The main idea of the algorithm is to push elements to the stack stack_b,
 * keeping the stack stack_b sorted in the descending order.
 * So when pushing back to a, the a will be sorted in the ascending order.
 * Upper node of the stack may be shifted.
 * For example the stack {3 4 5 1 2} is sorted, but the upper node is {1}.
 * (we need to perform only two rotations to make it sorted "for real" 1 2 3 4 5)
 */

#include "../push_swap.h"

void test(t_stack **stack_a, t_stack **stack_b);


/**
 * Function assigns to each node of the stack weight (number of operations needed
 * to transfer that node to the correct place in the stack_b, so that stack_b will remain sorted)
 * @param stack_a
 * @param stack_b
 */
void assign_weights(t_stack **stack_a, t_stack **stack_b);

/**
 * Finds the element, transfer of which will take the smallest amount of operations (sa, pb, sss, etc.)
 * @param stack
 * @return
 */
t_stack *find_cheapest_element(t_stack *stack);

/**
 * Function performs needed actions (bunch of sa, rb, ss, etc.)
 * to move stack_el of the stack_a to stack_b
 * @param stack_a
 * @param stack_b
 * @param stack_el the cheapest element
 */
void move_from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *stack_el);

/**
 * Function that manages all the action needed to make stack a sorted.
 * At the beginning pushes two upper elements of a.
 */
void main_algorithm(t_stack **stack_a, t_stack **stack_b);

int find_index_in_b(t_stack *stack_b, int value);

t_stack *find_max_node(t_stack *stack);

int find_min_value(t_stack *stack);

int find_max_value(t_stack *stack);

int find_mid_index(t_stack *stack);

/************* Bool utils *************/
t_stack *find_by_value(t_stack *stack, int value);

bool is_not_sorted(t_stack *stack);

bool in_first_a_second_b(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool in_second_a_first_b(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool in_first_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool in_second_half_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

bool can_rotate_both(t_stack *node, t_stack *stack_a, t_stack *stack_b, int index_in_b);

/************* Move utils *************/
void move_from_a_to_b_first_half(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b);

void move_second_a_first_b(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b);

void move_first_a_second_b(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b);

void move_second_half(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b);


/************* Score utils *************/
int find_score(t_stack *node_to_calculate, t_stack *stack_a, t_stack *stack_b);

int find_score_a(t_stack *node_to_move, t_stack *stack_a);

int find_score_b(t_stack *node, t_stack *stack_b, int *index_in_b);


/************* Sort utils *************/
void sort_three_element_stack(t_stack **stack_a);

#endif //FT_PUSH_SWAP_FT_ALGORITHM_H
