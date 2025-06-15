#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"
#include "../printf.h"

void	ft_print_fmt_number(int number, t_fmt *fmt);

// helper to print using standard printf
void print_with_printf(int number, t_fmt *fmt) {
    char format[20] = "%";

    if (fmt->minus) strcat(format, "-");
    if (fmt->plus)  strcat(format, "+");
    if (fmt->space) strcat(format, " ");
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

    strcat(format, (fmt->specifier == 'i') ? "i" : "d");

    printf(format, number);
}

void test_fmt(int number, t_fmt *fmt, const char *desc) {
    printf("Test: %s\n", desc);

    printf("Standard printf : \"");
    print_with_printf(number, fmt);
    printf("\"\n");

    printf("ft_print_fmt_number: \"");
    fflush(stdout);
    ft_print_fmt_number(number, fmt);
    fflush(stdout);
    printf("\"\n\n");
}

int main() {
    t_fmt fmt;

    // 1. Basic number
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = -1;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Basic positive number");

    // 2. Width and right-align
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 6;
    fmt.precision = -1;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Width = 6, right-aligned");

    // 3. Width and left-align
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 6;
    fmt.minus = 1;
    fmt.precision = -1;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Width = 6, left-aligned");

    // 4. Zero padding (width, no precision)
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 6;
    fmt.zero = 1;
    fmt.precision = -1;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Zero padding (width=6)");

    // 5. Precision with more digits
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = 5;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Precision = 5");

    // 6. Width and precision (zero flag ignored)
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 8;
    fmt.precision = 5;
    fmt.zero = 1; // should be ignored
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Width = 8, Precision = 5, Zero flag ignored");

    // 7. Sign handling (+ flag)
    memset(&fmt, 0, sizeof(fmt));
    fmt.plus = 1;
    fmt.precision = -1;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Plus flag: always show +");

    // 8. Space flag (no + sign)
    memset(&fmt, 0, sizeof(fmt));
    fmt.space = 1;
    fmt.precision = -1;
    fmt.specifier = 'd';
    test_fmt(42, &fmt, "Space flag: prepend space if no sign");

    // 9. Negative number with precision
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = 6;
    fmt.specifier = 'd';
    test_fmt(-42, &fmt, "Negative number, precision = 6");

    // 10. Number is zero and precision is zero → should print nothing
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = 0;
    fmt.specifier = 'd';
    test_fmt(0, &fmt, "Zero value, precision = 0 → should print nothing");

	// 11. Width only (right-aligned)
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Width = 5 → right-aligned");

	// 12. Precision only
	memset(&fmt, 0, sizeof(fmt));
	fmt.precision = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Precision = 5 → pad with leading zeros");

	// 13. Width > precision
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 5;
	fmt.precision = 3;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Width = 5, Precision = 3");

	// 14. Precision > width
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 3;
	fmt.precision = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Precision = 5, Width = 3 → width ignored");

	// 15. Plus flag
	memset(&fmt, 0, sizeof(fmt));
	fmt.plus = 1;
	fmt.width = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Plus flag → show + sign");

	// 16. Space flag
	memset(&fmt, 0, sizeof(fmt));
	fmt.space = 1;
	fmt.width = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Space flag → leading space for positive");

	// 17. Minus flag (left-aligned)
	memset(&fmt, 0, sizeof(fmt));
	fmt.minus = 1;
	fmt.width = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Minus flag → left-aligned");

	// 18. Zero-padding (no precision)
	memset(&fmt, 0, sizeof(fmt));
	fmt.zero = 1;
	fmt.width = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Zero flag → pad with 0s");

	// 19. Zero-padding ignored due to precision
	memset(&fmt, 0, sizeof(fmt));
	fmt.zero = 1;
	fmt.width = 8;
	fmt.precision = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Zero ignored due to precision → space pad, 00042");

	// 20. All flags: plus, zero, width, precision
	memset(&fmt, 0, sizeof(fmt));
	fmt.plus = 1;
	fmt.zero = 1;
	fmt.width = 8;
	fmt.precision = 5;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Plus + zero + width + precision");

	// 21. Negative number with precision and width
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 8;
	fmt.precision = 5;
	fmt.specifier = 'd';
	test_fmt(-42, &fmt, "Negative number, Width = 8, Precision = 5");

	// 22. Precision equals number of digits
	memset(&fmt, 0, sizeof(fmt));
	fmt.precision = 2;
	fmt.specifier = 'd';
	test_fmt(42, &fmt, "Precision = digit count → no extra zero padding");

	// 23. Precision smaller than digit count
	memset(&fmt, 0, sizeof(fmt));
	fmt.precision = 1;
	fmt.specifier = 'd';
	test_fmt(12345, &fmt, "Precision < digit count → precision ignored");

	// 24. Zero with width, precision = 0
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 5;
	fmt.precision = 0;
	fmt.specifier = 'd';
	test_fmt(0, &fmt, "Zero value, precision = 0, width = 5 → space padded");

	// Test: Value = 0, Precision = 3 → should print "000"
	memset(&fmt, 0, sizeof(fmt));
	fmt.precision = 3;
	fmt.specifier = 'd';
	test_fmt(0, &fmt, "Value=0, precision=3 → should print \"000\"");

	return 0;
}
