#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/libft.h"
#include "../src/printf.h"

// Helper to run and compare results
void test_hex(unsigned int value, const char *desc) {
    char *hex_str = ft_to_hexbase(value);
    printf("Test: %s\n", desc);
    printf("Input value: %u (0x%X)\n", value, value);
    printf("Output string: %s\n\n", hex_str);
    free(hex_str);
}

int main(void) {
    test_hex(0,        "Zero");
    test_hex(1,        "One");
    test_hex(10,       "Ten");
    test_hex(42,       "Forty-two");
    test_hex(255,      "Max 8-bit");
    test_hex(0xDEADBEEF, "Large hex literal");
    test_hex(4294967295u, "Max unsigned int (0xFFFFFFFF)");

    return 0;
}
