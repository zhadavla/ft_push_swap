#include "push_swap.h"

// main function receives argv argument
int main(int argc, char **argv) {
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))  //If no parameters are specified, the program must not display anything and give the prompt back.
        return (0);
    if (error_check(argc, argv)) {
        write(1, "Error\n", 6);
        return (0);
    }

    stack_a = get_input(argc, argv);
    sort(&stack_a, &stack_b);
    ft_free(&stack_a, &stack_b);
    return (0);
}

