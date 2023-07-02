#include "stack.h"

/**
 * free up allocated memory
 * @param stack
 */
void clean_stack(t_stack **stack) {
    t_stack *current;
    t_stack *next;

    current = *stack;
    if (*stack == NULL)
        return;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

/**
 * appending element
 * @param lst stack to append to
 * @param new element to append
 */
void ft_lstadd_back(t_stack **lst, t_stack *new) {
    t_stack *x;

    if (!*lst) {
        *lst = new;
        new->next = NULL;
        return;
    }
    x = *lst;
    while (x->next != NULL)
        x = x->next;

    x->next = new;
    new->next = NULL;
}

/**
 * inserts element in the beginning of the list
 * @param lst stack to insert
 * @param new element to insert
 */
void ft_lstadd_front(t_stack **lst, t_stack *new) {
    new->next = *lst;
    *lst = new;
}

/**
 * finds len of the list
 * @param lst
 * @return len of the list
 */
int ft_lstsize(t_stack *lst) {
    t_stack *x;
    int counter;

    x = lst;
    counter = 0;
    while (x != NULL) {
        counter++;
        x = x->next;
    }
    return (counter);
}
