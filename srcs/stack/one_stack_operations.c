#include "../push_swap.h"

/**
 * reverse two upper elements in stack
 * {sa} or {sb}
 * @param stack stack to swap
 * @param needs_to_print
 */
void stack_swap(t_stack **stack, bool needs_to_print) {
    t_stack *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;

    if (needs_to_print){
        if ((*stack)->is_a)
            write(1, "sa\n", 3);
        else
            write(1, "sb\n", 3);
    }
}

/**
 * pushes upper element from stack_from to stack_to
 * {pb, pa}
 * @param stack_from
 * @param stack_to
 */
void stack_push_to(t_stack **stack_from, t_stack **stack_to) {
    t_stack *to_push;

    if (!*stack_from)
        return;

    to_push = *stack_from;
    to_push->is_a = false;
    *stack_from = (*stack_from)->next;

    ft_lstadd_front(stack_to, to_push);

    if ((*stack_to)->is_a)
        write(1, "pa\n", 3);
    else
        write(1, "pb\n", 3);
}

/**
 * rotates the stack, meaning shifting all element one position forward
 * so that 1 2 3 4 becomes 2 3 4 1
 * {ra, rb}
 * @param stack
 * @param needs_to_print
 */
void rotate_stack(t_stack **stack, int needs_to_print) {
    t_stack *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;
    *stack = (*stack)->next;
    ft_lstadd_back(stack, tmp);

    if (needs_to_print){
        if ((*stack)->is_a)
            write(1, "ra\n", 3);
        else
            write(1, "rb\n", 3);
    }
}

/**
 * rotates the stack, meaning shifting all element one position backward
 * so that 1 2 3 4 becomes 4 1 2 3
 * @param stack
 * @param needs_to_print
 */
void reverse_rotate_stack(t_stack **stack, int needs_to_print) {
    t_stack *tmp;
    t_stack *last_el_in_stack;

    tmp = *stack;

    while (tmp->next->next != NULL)
        tmp = tmp->next; // iterate till the last element

    last_el_in_stack = tmp->next;
    tmp->next = NULL; // making element before the last, last
    last_el_in_stack->next = *stack;
    *stack = last_el_in_stack;

    if (needs_to_print){
        if ((*stack)->is_a)
            write(1, "rra\n", 4);
        else
            write(1, "rrb\n", 4);
    }
}
