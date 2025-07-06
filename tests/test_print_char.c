#include "../src/libft.h"
#include "../src/printf.h"
#include <stdio.h>

int	ft_print_fmt_char(char c, t_fmt *fmt); // your function

// helper to visualize padding output using quotes
void	test_char_output(char c, int width, int left_align) {
	t_fmt fmt;
	fmt.width = width;
	fmt.minus = left_align;

	printf("Input: '%c', width: %d, left_align: %d\n", c, width, left_align);
	printf("Expected output: \"");

	if (!left_align && width > 1)
		for (int i = 1; i < width; i++) putchar(' ');
	putchar(c);
	if (left_align && width > 1)
		for (int i = 1; i < width; i++) putchar(' ');

	printf("\"\nYour output    : \"");
	fflush(stdout); // ensure aligned output

	// Call your function and print the output inline
	ft_print_fmt_char(c, &fmt);

	printf("\"\n\n");
}

int main(void) {
	test_char_output('A', 1, 0);  // just 'A'
	test_char_output('B', 5, 0);  // right aligned
	test_char_output('C', 5, 1);  // left aligned
	test_char_output('D', 3, 0);  // right aligned small width
	test_char_output('E', 3, 1);  // left aligned small width
	return 0;
}
