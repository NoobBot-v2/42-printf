#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "../src/libft.h"
#include "../src/printf.h"

int ft_print_fmt_ptr(void *ptr, t_fmt *fmt);

// Helper to simulate standard printf behavior for comparison
void print_with_printf(void *ptr, t_fmt *fmt) {
    char format[32] = "%";

    if (fmt->minus) strcat(format, "-");
    if (fmt->zero)  strcat(format, "0");

    if (fmt->width) {
        char width_buf[10];
        sprintf(width_buf, "%d", fmt->width);
        strcat(format, width_buf);
    }

    strcat(format, "p"); // always use %p for pointers

    printf(format, ptr);
}

void test_fmt(void *ptr, t_fmt *fmt, const char *desc) {
    printf("Test: %s\n", desc);

    printf("Standard printf      : \"");
    print_with_printf(ptr, fmt);
    printf("\"\n");

    printf("ft_print_fmt_ptr     : \"");
    fflush(stdout);
    int count = ft_print_fmt_ptr(ptr, fmt);
    fflush(stdout);
    printf("\" (printed_count: %d)\n\n", count);
}

int main() {
    t_fmt fmt;
    int x = 42;
    void *ptr1 = &x;
    void *ptr2 = NULL;
    void *ptr3 = (void *)0x1234abcd;

    // 1. Basic pointer
    memset(&fmt, 0, sizeof(fmt));
    test_fmt(ptr1, &fmt, "Basic pointer");

    // 2. Right-aligned, width 20
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 20;
    test_fmt(ptr1, &fmt, "Right-aligned with width 20");

    // 3. Left-aligned, width 20
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 20;
    fmt.minus = 1;
    test_fmt(ptr1, &fmt, "Left-aligned with width 20");

    // 4. Null pointer with width
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    test_fmt(ptr2, &fmt, "NULL pointer with width 10");

    // 5. Custom pointer address
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 18;
    test_fmt(ptr3, &fmt, "Custom address pointer with width 18");

    return 0;
}
