#include "ft_algorithm.h"

void init_stack(t_stack *pStack);

t_stack *find_cheapest_element(t_stack *stack) {
    int smallest_weight;

    while (stack != NULL) {
        if (stack->weight == 1)
            return stack;
        if (stack->weight < smallest_weight) {
            smallest_weight = stack->weight;
            stack = stack->next;
        }
        return find_by_value(stack, smallest_weight);
    }

    void one_iteration(t_stack **stack_a, t_stack **stack_b, t_stack **current_node, t_stack **cheapest_node) {
        init_stack(*stack_a);
        init_stack(*stack_b);
        assign_weights(stack_a, stack_b);
        *cheapest_node = find_cheapest_element(*stack_a);
        printf("cheapest_node = %d\n", (*cheapest_node)->data);
        move_from_a_to_b(stack_a, stack_b, *cheapest_node);
        *current_node = (*current_node)->next;
    }

    void test(t_stack **stack_a, t_stack **stack_b) {
        t_stack *current_node;
        t_stack *cheapest_node;

        stack_push_to(stack_a, stack_b);
        stack_push_to(stack_a, stack_b);
        *stack_a = (*stack_a)->next->next;

        char str[3];
        while (1) {
            printf("stack size = %d\n", ft_lstsize(*stack_a));
            print_stacks(*stack_a, *stack_b);
            if (scanf("%s", str) == EOF) {
                break;
            }
            printf("str = %s\n", str);
            if (strncmp(str, "n", 1) == 0) {
                printf("cheapest_node = %d\n", (*cheapest_node).weight);
                one_iteration(stack_a, stack_b, &current_node, &cheapest_node);
            }
            if (ft_lstsize(*stack_a) == 3)
                break;
        }

    }
}

void main_algorithm(t_stack **stack_a, t_stack **stack_b) {
    t_stack *current_node;
    t_stack *cheapest_node;

    stack_push_to(stack_a, stack_b);
    stack_push_to(stack_a, stack_b);
    current_node = (*stack_a)->next->next;
    (*stack_a)->next = current_node;


    while (ft_lstsize(*stack_a) > 3) {
        init_stack(*stack_a);
        init_stack(*stack_b);
        assign_weights(stack_a, stack_b);
        cheapest_node = find_cheapest_element(*stack_a);
        move_from_a_to_b(stack_a, stack_b, cheapest_node);
        current_node = current_node->next;
    }

    if (is_not_sorted(*stack_a))
        sort_three_element_stack(stack_a);

    print_stacks(*stack_a, *stack_b);
}

void init_stack(t_stack *stack) {
    t_stack *elem;
    int i;

    elem = stack;
    i = 0;
    while (elem != NULL) {
        elem->index = i;
        elem->weight = 0;
        elem = elem->next;
        i++;
    }
}


