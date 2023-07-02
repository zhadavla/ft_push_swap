#include "stack.h"

void print_stacks(t_stack *a, t_stack *b) {
    printf("a:       b:\n");
    t_stack *temp_a = a;
    t_stack *temp_b = b;
    while (temp_a != NULL || temp_b != NULL) {
        char *a_data = temp_a != NULL ? ft_itoa(temp_a->data) : " ";
        char *b_data = temp_b != NULL ? ft_itoa(temp_b->data) : " ";

        char ch1 = temp_a != NULL ? temp_a->is_a ? 'a' : 'b' : ' ';
        char ch2 = temp_b != NULL ? temp_b->is_a ? 'a' : 'b' : ' ';

        char ch11 = temp_a ? temp_a->score != -1 ? temp_a->score : ' ' : ' ';
        printf("%s %c      | %s %c score: %d\n", a_data, ch1, b_data, ch2, ch11);
        if (temp_b)
            temp_b = temp_b->next;
        if (temp_a)
            temp_a = temp_a->next;
    }
}

/**
 * temporary function just to see what happening in the program
 * @param stack_a
 * @param stack_b
 */
void execute_command(t_stack *stack_a, t_stack *stack_b) {
    char str[4];
    do {

        printf("Enter command: ");
        if (scanf("%s", str) == EOF)
            break;

        if (!strcmp(str, "sa")) {
            system("clear");
            stack_swap(&stack_a, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "sb")) {
            system("clear");
            stack_swap(&stack_b, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "ss")) {
            system("clear");
            stack_swap(&stack_a, true);
            stack_swap(&stack_b, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "pa")) {
            system("clear");
            stack_push_a(&stack_a, &stack_b);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "pb")) {
            system("clear");
            stack_push_to(&stack_a, &stack_b);
            print_stacks(stack_a, stack_b);
        }


        if (!strcmp(str, "ra")) {
            system("clear");
            stack_rotate(&stack_a, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "rb")) {
            system("clear");
            stack_rotate(&stack_b, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "rrb")) {
            system("clear");
            stack_reverse_rotate(&stack_b, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "rra")) {
            system("clear");
            stack_reverse_rotate(&stack_a, true);
            print_stacks(stack_a, stack_b);
        }

        if (!strcmp(str, "rrr")) {
            system("clear");
            rrr(&stack_a, &stack_b);
            print_stacks(stack_a, stack_b);
        }

//        if (!strcmp(str, "sc")){
//            system("clear");
//            assign_scores(&stack_a, &stack_b);
//            print_stacks(stack_a, stack_b);
//        }

        if (!strcmp(str, "pr")){
            system("clear");
            print_stacks(stack_a, stack_b);
        }

    } while (true);
}
