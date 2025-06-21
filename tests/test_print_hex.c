#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"
#include "../printf.h"

// Helper to build standard printf format
void print_with_printf(unsigned int number, t_fmt *fmt) {
	char format[32] = "%";

	if (fmt->minus) strcat(format, "-");
	if (fmt->plus)  strcat(format, "+");
	if (fmt->space) strcat(format, " ");
	if (fmt->hash)  strcat(format, "#");
	if (fmt->zero && !fmt->minus && fmt->precision < 0) strcat(format, "0");

	if (fmt->width > 0) {
		char buf[10];
		sprintf(buf, "%d", fmt->width);
		strcat(format, buf);
	}

	if (fmt->precision >= 0) {
		char buf[10];
		sprintf(buf, ".%d", fmt->precision);
		strcat(format, buf);
	}

	strcat(format, (fmt->specifier == 'X') ? "X" : "x");

	printf(format, number);
}

void test_fmt(unsigned int value, t_fmt *fmt, const char *desc) {
	printf("Test: %s\n", desc);

	printf("Standard printf : \"");
	print_with_printf(value, fmt);
	printf("\"\n");

	printf("ft_print_fmt_hex: \"");
	fflush(stdout);
	ft_print_fmt_hex(fmt, value);
	fflush(stdout);
	printf("\"\n\n");
}
int main() {
	t_fmt fmt;

	// Zero value, precision 0
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = -2;
	fmt.precision = 0;
	fmt.specifier = 'x';
	test_fmt(0, &fmt, "Zero value, precision 0");

	// Zero value, precision 0, hash
	fmt.hash = 1;
	test_fmt(0, &fmt, "Zero value, precision 0, hash");

	// Uppercase hex
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

	// Value & precision is 0 but width != 0
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 5;
	fmt.precision = 0;
	fmt.specifier = 'x';
	test_fmt(0, &fmt, "Value 0, precision 0, width 5");
	
	memset(&fmt, 0, sizeof(fmt));
	fmt.width = 8;            // total field width
	fmt.precision = -2;       // no precision specified
	fmt.specifier = 'x';      // lowercase hex
	test_fmt(0x2A, &fmt, "Width 8, right-justified (default)");
	
	return 0;
}
