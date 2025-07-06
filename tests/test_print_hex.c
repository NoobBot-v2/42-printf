#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/libft.h"
#include "../src/printf.h"

int	ft_print_fmt_hex(unsigned int hex_num, t_fmt *fmt);

// Helper to simulate standard printf behavior for hex
void print_with_printf(unsigned int hex_num, t_fmt *fmt) {
    char format[32] = "%";

    if (fmt->minus) strcat(format, "-");
    if (fmt->zero && fmt->precision < 0 && !fmt->minus) strcat(format, "0");

    if (fmt->width) {
        char width_buf[10];
        sprintf(width_buf, "%d", fmt->width);
        strcat(format, width_buf);
    }

    if (fmt->precision >= 0) {
        char prec_buf[10];
        sprintf(prec_buf, ".%d", fmt->precision);
        strcat(format, prec_buf);
    }

    strcat(format, (fmt->specifier == 'X') ? "X" : "x");

    printf(format, hex_num);
}

// Comparison runner
void test_fmt(unsigned int hex_num, t_fmt *fmt, const char *desc) {
    printf("Test: %s\n", desc);

    printf("Standard printf      : \"");
    print_with_printf(hex_num, fmt);
    printf("\"\n");

    printf("ft_print_fmt_hex     : \"");
    fflush(stdout);
    int count = ft_print_fmt_hex(hex_num, fmt);
    fflush(stdout);
    printf("\" (printed_count: %d)\n\n", count);
}

int main() {
    t_fmt fmt;

    // 1. Basic lowercase hex
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = -1;
    fmt.specifier = 'x';
    test_fmt(0x1a3f, &fmt, "Lowercase hex basic");

    // 2. Basic uppercase hex
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = -1;
    fmt.specifier = 'X';
    test_fmt(0x1a3f, &fmt, "Uppercase hex basic");

    // 3. Width right-aligned
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.precision = -1;
    fmt.specifier = 'x';
    test_fmt(0xab, &fmt, "Width 10, right-aligned");

    // 4. Width left-aligned
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.minus = 1;
    fmt.precision = -1;
    fmt.specifier = 'x';
    test_fmt(0xab, &fmt, "Width 10, left-aligned");

    // 5. Precision padded
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = 6;
    fmt.width = 0;
    fmt.specifier = 'x';
    test_fmt(0x3c, &fmt, "Precision 6, no width");

    // 6. Zero-padding with width
    memset(&fmt, 0, sizeof(fmt));
    fmt.zero = 1;
    fmt.width = 8;
    fmt.precision = -2;
    fmt.specifier = 'x';
    test_fmt(0x7d, &fmt, "Zero padding, width 8");

    // 7. Zero-padding suppressed by precision
    memset(&fmt, 0, sizeof(fmt));
    fmt.zero = 1;
    fmt.width = 8;
    fmt.precision = 4;
    fmt.specifier = 'x';
    test_fmt(0x7d, &fmt, "Zero flag ignored (precision present)");

    // 8. Both width and precision
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.precision = 4;
    fmt.specifier = 'x';
    test_fmt(0x1f3, &fmt, "Width 10, precision 4");

    return 0;
}
