#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../src/libft.h"
#include "../src/printf.h"

// Wrapper to compare ft_printf and standard printf output and return counts
void test_fmt(const char *desc, const char *format, ...) {
    va_list args1, args2;
    int std_len, ft_len;

    printf("Test: %s\n", desc);
    printf("Format string: \"%s\"\n", format);

    va_start(args1, format);
    va_start(args2, format);

	printf("Standard printf      : \"");
	fflush(stdout);  // flush before vprintf to avoid mixing buffered and unbuffered
	std_len = vprintf(format, args1);
	fflush(stdout);  // flush after to ensure all printed before next output
	printf("\" (printed_count: %d)\n", std_len);
	
	printf("ft_printf            : \"");
	fflush(stdout);  // flush before ft_printf
	ft_len = ft_printf(format, va_arg(args2, void *), va_arg(args2, void *), va_arg(args2, void *));
	fflush(stdout);  // flush after ft_printf
	printf("\" (printed_count: %d)\n", ft_len);
	

    va_end(args1);
    va_end(args2);

    printf("\n");
}

int main(void) {
    char c = 'A';
    char *s = "Hello";
    int i = -42;
    unsigned int u = 3000000000U;
    void *p = s;
    int d = 123;
    int x = 0x1a3f;

    test_fmt("%%c - character", "%c", c);
    test_fmt("%%s - string", "%s", s);
    test_fmt("%%i - signed int", "%i", i);
    test_fmt("%%d - signed int", "%d", d);
    test_fmt("%%x - lowercase hex", "%x", x);
    test_fmt("%%X - uppercase hex", "%X", x);
    test_fmt("%%p - pointer", "%p", p);
    test_fmt("%%u - unsigned int", "%u", u);
    test_fmt("%%%% - percent sign", "%%");

    return 0;
}
