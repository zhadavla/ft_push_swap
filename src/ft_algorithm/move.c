#include "ft_algorithm.h"

void move_from_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *stack_el) {
    int score_a;
    int score_b;
    int index_in_b;

    score_a = find_score_a(stack_el, *stack_a);
    score_b = find_score_b(stack_el, *stack_b, &index_in_b);
    if (in_first_half_both(stack_el, *stack_a, *stack_b, index_in_b))
        move_from_a_to_b_first_half(stack_a, stack_b, score_a, score_b);
    else if (in_second_half_both(stack_el, *stack_a, *stack_b, index_in_b))
        move_second_half(stack_a, stack_b, score_a, score_b);
    else if (in_first_a_second_b(stack_el, *stack_a, *stack_b, index_in_b))
        move_first_a_second_b(stack_a, stack_b, score_a, score_b);
    else if (in_second_a_first_b(stack_el, *stack_a, *stack_b, index_in_b))
        move_second_a_first_b(stack_a, stack_b, score_a, score_b);
    stack_push_to(stack_a, stack_b);
}

void move_first_a_second_b(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b) {
    while (score_a-- != 0)
        rotate_stack(stack_a, true);
    while (score_b-- != 0)
        reverse_rotate_stack(stack_b, true);
}

void move_second_a_first_b(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b) {
    while (score_a--)
        reverse_rotate_stack(stack_a, true);
    while (score_b--)
        rotate_stack(stack_b, true);
}

void move_second_half(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b) {
    if (score_a <= score_b) {
        score_b -= score_a;
        while (score_a-- != 0)
            rrr(stack_a, stack_b);
        while (score_b-- != 0)
            reverse_rotate_stack(stack_b, true);
    } else if (score_b < score_a) {
        score_a -= score_b;
        while (score_b-- != 0)
            rrr(stack_a, stack_b);
        while (score_a-- != 0)
            reverse_rotate_stack(stack_a, true);
    }
}

void move_from_a_to_b_first_half(t_stack **stack_a, t_stack **stack_b, int score_a, int score_b) {
    if (score_a <= score_b) {
        score_b -= score_a;
        while (score_a-- != 0)
            rr(stack_a, stack_b);
        while (score_b-- != 0)
            rotate_stack(stack_b, true);
    } else if (score_b < score_a) {
        score_a -= score_b;
        while (score_b-- != 0)
            rr(stack_a, stack_b);
        while (score_a-- != 0)
            rotate_stack(stack_a, true);
    }

}
