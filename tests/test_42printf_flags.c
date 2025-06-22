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

int main()
{char c = 'A';
	char *s = "hello";
	int d = -42;
	unsigned int u = 3000000000U;
	void *p = s;
	int x = 0x1a3f;
	int i = 123;
	
	// %c tests
	test_fmt("%%c - basic character", "%c", c);
	test_fmt("%%c - left justify", "%-c", c);
	
	// %s tests
	test_fmt("%%s - basic string", "%s", s);
	test_fmt("%%s - left justify", "%-10s", s);
	test_fmt("%%s - precision", "%.3s", s);
	
	// %p tests
	test_fmt("%%p - pointer", "%p", p);
	test_fmt("%%p - with zero pad (ignored in standard printf)", "%020p", p);
	
	// %d and %i tests (signed int)
	test_fmt("%%d - positive", "%d", i);
	test_fmt("%%d - negative", "%d", d);
	test_fmt("%%i - positive", "%i", i);
	test_fmt("%%i - with plus flag", "%+i", i);
	test_fmt("%%i - with space flag", "% i", i);
	test_fmt("%%d - zero pad", "%010d", i);
	test_fmt("%%d - left justify", "%-10d", i);
	
	// %u tests (unsigned int)
	test_fmt("%%u - basic unsigned", "%u", u);
	test_fmt("%%u - zero pad", "%010u", u);
	test_fmt("%%u - left justify", "%-10u", u);
	
	// %x tests (hex lowercase)
	test_fmt("%%x - basic hex", "%x", x);
	test_fmt("%%x - with # flag", "%#x", x);
	test_fmt("%%x - zero pad", "%010x", x);
	test_fmt("%%x - left justify", "%-10x", x);
	
	// %X tests (hex uppercase)
	test_fmt("%%X - basic hex uppercase", "%X", x);
	test_fmt("%%X - with # flag", "%#X", x);
	test_fmt("%%X - zero pad", "%010X", x);
	test_fmt("%%X - left justify", "%-10X", x);
	
	// %% tests (literal % sign)
	test_fmt("%%%% - percent sign", "%%");
	test_fmt("%%%% - percent with width", "%5%");
	test_fmt("%%%% - percent with left justify", "%-5%");
		
	return 0;
}
