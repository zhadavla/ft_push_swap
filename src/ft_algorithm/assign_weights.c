#include "ft_algorithm.h"



void assign_weights(t_stack **stack_a, t_stack **stack_b) {
    t_stack *current_node;

    current_node = *stack_a;
    while (current_node) {
        current_node->weight = find_score(current_node, *stack_a, *stack_b);
        current_node = current_node->next;
    }
}

int find_score(t_stack *node_to_calculate, t_stack *stack_a, t_stack *stack_b) {
    int score_a;
    int score_b;
    int index_in_b;

    score_a = find_score_a(node_to_calculate, stack_a);
    score_b = find_score_b(node_to_calculate, stack_b, &index_in_b);

    if (can_rotate_both(node_to_calculate, stack_a, stack_b, index_in_b)
        && score_a != 0 && score_b != 0) {
        if (score_a <= score_b)
            score_a = 0;
        else if (score_b < score_a) // todo redundant???
            score_b = 0;
    }
    return score_a + score_b + 1;
}

int find_score_b(t_stack *node, t_stack *stack_b, int *index_in_b) {
    int index;

    index = find_index_in_b(stack_b, node->data);
    *index_in_b = index;
    if (index < find_max_value(stack_b))
        return index;
    return ft_lstsize(stack_b) - index;
}

int find_index_of_node(t_stack *node, t_stack *stack) {
    int index;

    index = 0;
    while (node->data != stack->data && stack != NULL) {
        index++;
        stack = stack->next;
    }
    return index;
}

/*
 * Finds number of moves to move node_to_move to the top of the stack_a.
 * If element before the middle point, it can be moved to the top by performing {index_in_stack} ra
 * otherwise {stack_size - index_in_stack} rra
 */
int find_score_a(t_stack *node_to_move, t_stack *stack_a) {
    int index_in_stack;
    int mid_index;

    index_in_stack = find_index_of_node(node_to_move, stack_a);
    mid_index = find_mid_index(stack_a);

    if (index_in_stack < mid_index)
        return index_in_stack;
    return ft_lstsize(stack_a) - index_in_stack;
}



//int find_index_of_lowest_element()

t_stack *get_last_element(t_stack *stack) {
    while (stack->next)
        stack = stack->next;
    return stack;
}

/*
 * Finds index of the element in stack_b to which node_to_move should be moved.
 * if value is less than min_value or greater than max_value, it should be moved to the top of the stack
 * otherwise, it should be moved to the element which is greater than value and the next element is less than value
 */
int find_index_in_b(t_stack *stack_b, int value) {
    int index;

    if (value < find_min_value(stack_b) || value > find_max_value(stack_b))
        return find_max_node(stack_b)->index; // element should be right before the max element

    // todo redundant???
    if (value < get_last_element(stack_b)->data && value > stack_b->data)
        return 0;

    index = 1;
    while (stack_b->next != NULL
           && !(value < stack_b->data && value > stack_b->next->data)) {
        index++;
        stack_b = stack_b->next;
    }
    return index;
}

