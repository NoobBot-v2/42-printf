#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/libft.h"
#include "../src/printf.h"

int	ft_print_fmt_unsigned(unsigned int number, t_fmt *fmt);

void print_with_printf_unsigned(unsigned int number, t_fmt *fmt) {
    char format[20] = "%";

    // Don't add '+' or ' ' for unsigned as they're ignored by printf
    if (fmt->minus) strcat(format, "-");
    if (fmt->zero)  strcat(format, "0");

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

    strcat(format, "u");

    printf(format, number);
}

void test_fmt_unsigned(unsigned int number, t_fmt *fmt, const char *desc) {
    printf("Test: %s\n", desc);

    printf("Standard printf : \"");
    print_with_printf_unsigned(number, fmt);
    printf("\"\n");

    printf("ft_print_fmt_unsigned: \"");
    fflush(stdout);
    printf(" print_count:%i",ft_print_fmt_unsigned(number, fmt));
    fflush(stdout);
    printf("\"\n\n");
}


int main() {
    t_fmt fmt;

    // Basic unsigned number
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = -1;
    fmt.specifier = 'u';
    test_fmt_unsigned(42u, &fmt, "Basic unsigned number");

    // Width 10, right-align (default)
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.precision = -1;
    fmt.specifier = 'u';
    test_fmt_unsigned(1234u, &fmt, "Width 10, right align");

    // Width 10, zero-padded
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.zero = 1;
    fmt.precision = -1;
    fmt.specifier = 'u';
    test_fmt_unsigned(1234u, &fmt, "Width 10, zero padded");

    // Precision 5 (minimum digits)
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = 5;
    fmt.specifier = 'u';
    test_fmt_unsigned(42u, &fmt, "Precision 5, minimal digits");

    // Width 10, precision 5
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.precision = 5;
    fmt.specifier = 'u';
    test_fmt_unsigned(42u, &fmt, "Width 10, precision 5");

    // Width 10, left-align
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.minus = 1;
    fmt.precision = -1;
    fmt.specifier = 'u';
    test_fmt_unsigned(42u, &fmt, "Width 10, left align");

    // Max unsigned int
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = -1;
    fmt.specifier = 'u';
    test_fmt_unsigned(4294967295u, &fmt, "Max unsigned int");

		// Test that '+' flag is ignored for unsigned
	memset(&fmt, 0, sizeof(fmt));
	fmt.plus = 1;             // '+' flag set, should be ignored
	fmt.specifier = 'u';
	fmt.precision = -1;
	test_fmt_unsigned(123u, &fmt, "'+' flag ignored");

	// Test that 'space' flag is ignored for unsigned
	memset(&fmt, 0, sizeof(fmt));
	fmt.space = 1;            // space flag set, should be ignored
	fmt.specifier = 'u';
	fmt.precision = -1;
	test_fmt_unsigned(456u, &fmt, "'space' flag ignored");

	// Test '+' and 'space' both set, still ignored
	memset(&fmt, 0, sizeof(fmt));
	fmt.plus = 1;
	fmt.space = 1;
	fmt.specifier = 'u';
	fmt.precision = -1;
	test_fmt_unsigned(789u, &fmt, "'+' and 'space' flags ignored");

	// Test '+' and 'space' with width and zero padding (should ignore sign flags)
	memset(&fmt, 0, sizeof(fmt));
	fmt.plus = 1;
	fmt.space = 1;
	fmt.zero = 1;
	fmt.width = 10;
	fmt.specifier = 'u';
	fmt.precision = -1;
	test_fmt_unsigned(42u, &fmt, "'+' and 'space' flags with width and zero padding ignored");

	// Test '+' and 'space' with precision and width
	memset(&fmt, 0, sizeof(fmt));
	fmt.plus = 1;
	fmt.space = 1;
	fmt.width = 10;
	fmt.precision = 5;
	fmt.specifier = 'u';
	test_fmt_unsigned(42u, &fmt, "'+' and 'space' flags with width and precision ignored");

    return 0;
}
