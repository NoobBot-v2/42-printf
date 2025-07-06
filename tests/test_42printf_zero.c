#include <stdio.h>

// Assume ft_printf is declared somewhere
int ft_printf(const char *fmt, ...);

int main(void)
{
    int ret1, ret2;

    printf("=== Testing precision 0 and value 0 ===\n");

    // %d with precision 0 and value 0
    ret1 = printf("std:  [%5.0d]\n", 0);
    ret2 = ft_printf("ft:   [%5.0d]\n", 0);
    printf("std printed chars: %d, ft printed chars: %d\n\n", ret1, ret2);

    // %u with precision 0 and value 0
    ret1 = printf("std:  [%5.0u]\n", 0u);
    ret2 = ft_printf("ft:   [%5.0u]\n", 0u);
    printf("std printed chars: %d, ft printed chars: %d\n\n", ret1, ret2);

    // %x with precision 0 and value 0
    ret1 = printf("std:  [%5.0x]\n", 0u);
    ret2 = ft_printf("ft:   [%5.0x]\n", 0u);
    printf("std printed chars: %d, ft printed chars: %d\n\n", ret1, ret2);

    // %X with precision 0 and value 0
    ret1 = printf("std:  [%5.0X]\n", 0u);
    ret2 = ft_printf("ft:   [%5.0X]\n", 0u);
    printf("std printed chars: %d, ft printed chars: %d\n\n", ret1, ret2);

    // %s with precision 0
    ret1 = printf("std:  [%.0s]\n", "hello");
    ret2 = ft_printf("ft:   [%.0s]\n", "hello");
    printf("std printed chars: %d, ft printed chars: %d\n\n", ret1, ret2);

    return 0;
}
