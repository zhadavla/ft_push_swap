#include "libft.h"

/**
 * getting array of ints from the array of the char-representation of ints
 * @param argv array of char-represented numbers
 * @param len
 * @return ar
 */
int *chars_to_ints(char **argv, int len) {
    int *ar;
    int i;

    ar = (int *) malloc(sizeof(*ar) * len);
    i = 1;
    while (i < len) {
        ar[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    return ar;
}
