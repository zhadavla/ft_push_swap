#include "stack.h"

/**
 * converting array to linked-list stack
 * @param array
 * @param len
 * @param is_a
 * @return
 */
t_stack *array_to_stack(const int *array, int len, bool is_a) {
    t_stack *top = NULL;
    int i;

    i = len - 1;
    while (i >= 0){
        t_stack *new_element = (t_stack *) malloc(sizeof(t_stack));
        new_element->data = array[i];
        new_element->index = i;
        new_element->score = -1;
        new_element->is_a = is_a;

        new_element->next = top;
        top = new_element;
        i--;
    }
    return top;
}

int *stack_to_array(t_stack *stack, int len) {
    int *array = (int *) malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        array[i] = stack->data;
        stack = stack->next;
    }

    return array;
}