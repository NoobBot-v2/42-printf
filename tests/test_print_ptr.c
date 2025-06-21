#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"
#include "../printf.h"

void ft_print_fmt_ptr(void *ptr, t_fmt *fmt);  // Your function

int main(void)
{
    int x = 42;
    t_fmt fmt = {
        .minus = 1,
        .plus = 0,
        .space = 0,
        .hash = 0,
        .zero = 0,
        .width = 20,
        .precision = -1,
        .specifier = 'p'
    };

    printf("Expected:\n");
    printf("%-20p\n", (void *)&x);  // Standard printf for reference

    printf("Your ft_print_fmt_ptr:\n");
    ft_print_fmt_ptr((void *)&x, &fmt);  // Your implementation

    return 0;
}
