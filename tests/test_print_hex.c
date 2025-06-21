#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"
#include "../printf.h"

void ft_print_fmt_hex(t_fmt *fmt, char *hex_str);
char	*ft_to_hexbase(unsigned int hex_num);

// helper to print using standard printf with constructed format string
void print_with_printf(unsigned int number, t_fmt *fmt) {
    char format[32] = "%";

    if (fmt->minus) strcat(format, "-");
    if (fmt->plus)  strcat(format, "+");
    if (fmt->space) strcat(format, " ");
    if (fmt->hash)  strcat(format, "#");
    if (fmt->zero && !fmt->minus && fmt->precision < 0) strcat(format, "0");

    if (fmt->width > 0) {
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

    printf(format, number);
}

void test_fmt(unsigned int number, t_fmt *fmt, const char *desc) {
    char *hex_str = ft_to_hexbase(number); // convert number to hex string

    printf("Test: %s\n", desc);

    printf("Standard printf : \"");
    print_with_printf(number, fmt);
    printf("\"\n");

    printf("print_fmt_hex     : \"");
    fflush(stdout);
    ft_print_fmt_hex(fmt, hex_str);
    fflush(stdout);
    printf("\"\n\n");

    free(hex_str);
}

int main() {
    t_fmt fmt;

    // Basic hex without flags
    memset(&fmt, 0, sizeof(fmt));
    fmt.width = -2;  // width unspecified
    fmt.precision = -2;  // precision unspecified
    fmt.specifier = 'x';
    test_fmt(42, &fmt, "Basic hex 42");

    // Hash flag
    fmt.hash = 1;
    test_fmt(42, &fmt, "Hash flag");

    // Width with zero padding
    fmt.hash = 0;
    fmt.zero = 1;
    fmt.width = 8;
    test_fmt(42, &fmt, "Width 8 + zero padding");

    // Left align with width
    fmt.zero = 0;
    fmt.minus = 1;
    fmt.width = 8;
    test_fmt(42, &fmt, "Width 8 + left align");

    // Width + precision
    fmt.minus = 0;
    fmt.width = 10;
    fmt.precision = 5;
    test_fmt(42, &fmt, "Width 10 + precision 5");

    // Hash + width + precision
    fmt.hash = 1;
    fmt.width = 12;
    fmt.precision = 6;
    test_fmt(42, &fmt, "Hash + width 12 + precision 6");
// Zero value, precision 0
memset(&fmt, 0, sizeof(fmt));
fmt.width = -2;
fmt.precision = 0;
fmt.specifier = 'x';
test_fmt(0, &fmt, "Zero value, precision 0");

// Zero value, precision 0, hash
fmt.hash = 1;
test_fmt(0, &fmt, "Zero value, precision 0, hash");

// Uppercase hex, no flags
memset(&fmt, 0, sizeof(fmt));
fmt.width = -2;
fmt.precision = -2;
fmt.specifier = 'X';
test_fmt(0xDEADBEEF, &fmt, "Uppercase hex");

// Width smaller than string length
memset(&fmt, 0, sizeof(fmt));
fmt.width = 3;
fmt.precision = -2;
fmt.specifier = 'x';
test_fmt(0x1234, &fmt, "Width smaller than string length");

// Width 8 zero padded
memset(&fmt, 0, sizeof(fmt));
fmt.zero = 1;
fmt.width = 8;
fmt.precision = -2;
fmt.specifier = 'x';
test_fmt(0x1f, &fmt, "Width 8 zero padded");

// Width 6 left align
memset(&fmt, 0, sizeof(fmt));
fmt.minus = 1;
fmt.width = 6;
fmt.precision = -2;
fmt.specifier = 'x';
test_fmt(0xabc, &fmt, "Width 6 left align");

// Precision 6 pads with zeros
memset(&fmt, 0, sizeof(fmt));
fmt.width = -2;
fmt.precision = 6;
fmt.specifier = 'x';
test_fmt(0x7f, &fmt, "Precision 6 pads with zeros");

// Width 10 + precision 6 + hash + zero + uppercase
memset(&fmt, 0, sizeof(fmt));
fmt.hash = 1;
fmt.zero = 1;
fmt.width = 10;
fmt.precision = 6;
fmt.specifier = 'X';
test_fmt(0x3A, &fmt, "Width 10 + precision 6 + hash + zero + uppercase");

// Plus and space flags on hex
memset(&fmt, 0, sizeof(fmt));
fmt.plus = 1;
fmt.space = 1;
fmt.width = -2;
fmt.precision = -2;
fmt.specifier = 'x';
test_fmt(0x10, &fmt, "Plus and space flags on hex");

    return 0;
}
