#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "../printf.h"

void ft_print_fmt_string(char *s1, t_fmt *fmt);

// Helper to print string with formatting using standard printf for comparison
void print_with_printf(char *input, t_fmt *fmt) {
    if (input == NULL)
        input = "(null)";

    // Build printf format dynamically to match fmt fields
    // Only handle -, width, precision for %s here
    char format[20] = "%";

    if (fmt->minus)
        strcat(format, "-");

    if (fmt->zero)
        strcat(format, "0");

    if (fmt->width > 0) {
        char width_str[10];
        sprintf(width_str, "%d", fmt->width);
        strcat(format, width_str);
    }

    if (fmt->precision >= 0) {
        char prec_str[10];
        sprintf(prec_str, ".%d", fmt->precision);
        strcat(format, prec_str);
    }

    strcat(format, "s");

    printf(format, input);
}

void test_ft_print_fmt_string(char *input, t_fmt *fmt, const char *desc) {
    printf("Test: %s\n", desc);

    printf("Standard printf : \"");
    print_with_printf(input, fmt);
    printf("\"\n");

	printf("ft_print_fmt_str: \"");
	fflush(stdout);              // flush label immediately
	ft_print_fmt_string(input, fmt);
	printf("\"\n\n");
	
}

int main() {
    t_fmt fmt;

    // Test 1: Simple string, no formatting
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = -1; // Disable precision
    fmt.specifier = 's';
    test_ft_print_fmt_string("Hello, world!", &fmt, "Simple string, no formatting");

    // Test 2: Width > string length, right-aligned (default)
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 20;
    fmt.precision = -1;
    fmt.specifier = 's';
    test_ft_print_fmt_string("Hi", &fmt, "Width=20, right-aligned (default)");

    // Test 3: Width > string length, left-aligned (minus=1)
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 20;
    fmt.minus = 1;
    fmt.precision = -1;
    fmt.specifier = 's';
    test_ft_print_fmt_string("Hi", &fmt, "Width=20, left-aligned (minus=1)");

    // Test 4: Precision cuts string
    memset(&fmt, 0, sizeof(fmt));
    fmt.precision = 4;
    fmt.specifier = 's';
    test_ft_print_fmt_string("Hello, world!", &fmt, "Precision=4 cuts string");

    // Test 5: Width and precision combined
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.precision = 3;
    fmt.specifier = 's';
    test_ft_print_fmt_string("Hello, world!", &fmt, "Width=10, Precision=3");

    // Test 6: Null string input (should print "(null)" or empty)
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = 10;
    fmt.precision = -1;
    fmt.specifier = 's';
    test_ft_print_fmt_string(NULL, &fmt, "Null string input");

    return 0;
}
