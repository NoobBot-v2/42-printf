#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/libft.h"
#include "../src/printf.h"

// Prototype for your parser
t_fmt *ft_parse_fmt(char **str);

// Helper: reset pointer to initial string each time
void reset_str(char **dst, const char *src) {
    *dst = (char *)src;
}

void test_ft_parse_fmt() {
    char *fmt;
    t_fmt *parsed;

    // 1. Basic specifier d
    fmt = "dHello";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->specifier == 'd');
    assert(parsed->minus == 0);
    assert(parsed->plus == 0);
    assert(parsed->space == 0);
    assert(parsed->hash == 0);
    assert(parsed->zero == 0);
    assert(parsed->width == -2);      // width not specified
    assert(parsed->precision == -2);  // precision not specified
    assert(fmt[0] == 'H');            // pointer advanced
    free(parsed);

    // 2. Flags: "-+ #0d"
    fmt = "-+ #0dX";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->minus == 1);
    assert(parsed->plus == 1);
    assert(parsed->space == 1);
    assert(parsed->hash == 1);
    assert(parsed->zero == 1);
    assert(parsed->specifier == 'd');
	assert(parsed->width == -2);      // width not specified
    assert(parsed->precision == -2);  // precision not specified
    assert(fmt[0] == 'X');
    free(parsed);

    // 3. Width with number: "10d"
    fmt = "10d!";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->width == 10);
	assert(parsed->precision == -2);  // precision not specified
    assert(parsed->specifier == 'd');
    assert(fmt[0] == '!');
    free(parsed);

    // 4. Precision with dot: ".5d"
    fmt = ".5d?";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->precision == 5);
	assert(parsed->width == -2);      // width not specified
    assert(parsed->specifier == 'd');
    assert(fmt[0] == '?');
    free(parsed);

    // 5. Width and precision: "8.3d"
    fmt = "8.3d.";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->width == 8);
    assert(parsed->precision == 3);
    assert(parsed->specifier == 'd');
    assert(fmt[0] == '.');
    free(parsed);

    // 6. Width and precision with * (assuming you store -1 for *)
    fmt = "*.*d:";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->width == -1);      // '*' for width
    assert(parsed->precision == -1);  // '*' for precision
    assert(parsed->specifier == 'd');
    assert(fmt[0] == ':');
    free(parsed);

    // 7. Percent literal ""
    fmt = "%abc";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed != NULL);
    assert(parsed->specifier == '%');
    assert(fmt[0] == 'a');
    free(parsed);

    // 8. Invalid specifier: "q"
    fmt = "q";
    parsed = ft_parse_fmt(&fmt);
    assert(parsed == NULL);       // should return NULL
    assert(fmt[0] == 'q');        // pointer may or may not advance, depending on your implementation

	// 9
	fmt = "*d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed != NULL);
	assert(parsed->width == -1);       // Convention: -1 or special flag for dynamic width
	assert(parsed->precision == -2);   // Not set
	assert(parsed->specifier == 'd');

	// Test 1: Width is '*'
	fmt = "*d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed);
	assert(parsed->width == -1);        // convention: -1 means dynamic
	assert(parsed->precision == -2);    // -2 = unset
	assert(parsed->specifier == 'd');

	// Test 2: Precision is '*'
	fmt = ".*d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed);
	assert(parsed->width == -2);
	assert(parsed->precision == -1);    // -1 = dynamic precision
	assert(parsed->specifier == 'd');

	// Test 3: Width and Precision are '*'
	fmt = "*.*d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed);
	assert(parsed->width == -1);
	assert(parsed->precision == -1);
	assert(parsed->specifier == 'd');

	// Test 4: Width is number, precision is '*'
	fmt = "10.*d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed);
	assert(parsed->width == 10);
	assert(parsed->precision == -1);
	assert(parsed->specifier == 'd');

	// Test 5: Width is '*', precision is number
	fmt = "*.5d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed);
	assert(parsed->width == -1);
	assert(parsed->precision == 5);
	assert(parsed->specifier == 'd');

	// Test 6: No width/precision
	fmt = "d";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed);
	assert(parsed->width == -2);
	assert(parsed->precision == -2);
	assert(parsed->specifier == 'd');

	fmt = "-+ 0dRest";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->minus == 1);
	assert(parsed->plus == 1);
	assert(parsed->space == 1);
	assert(parsed->hash == 0);     // ' ' is not a hash flag
	assert(parsed->zero == 1);
	assert(parsed->width == -2);      // Not specified
	assert(parsed->precision == -2);  // Not specified
	assert(fmt[0] == 'R');
	free(parsed);

	fmt = "-+ 0dRest";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->minus == 1);
	assert(parsed->plus == 1);
	assert(parsed->space == 1);
	assert(parsed->hash == 0);     // ' ' is not a hash flag
	assert(parsed->zero == 1);
	assert(parsed->width == -2);      // Not specified
	assert(parsed->precision == -2);  // Not specified
	assert(fmt[0] == 'R');
	free(parsed);
	
	fmt = "123dABC";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->width == 123);
	assert(parsed->precision == -2);
	assert(fmt[0] == 'A');
	free(parsed);

	fmt = "*dText";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->width == -1);   // Dynamic
	assert(parsed->precision == -2);
	assert(fmt[0] == 'T');
	free(parsed);

	fmt = ".5dZ";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->width == -2);
	assert(parsed->precision == 5);
	assert(fmt[0] == 'Z');
	free(parsed);

	fmt = ".*dQ";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->width == -2);
	assert(parsed->precision == -1); // Dynamic
	assert(fmt[0] == 'Q');
	free(parsed);
	
	fmt = "10.3d.";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->width == 10);
	assert(parsed->precision == 3);
	assert(fmt[0] == '.');
	free(parsed);

	fmt = "*.*d;";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->width == -1);
	assert(parsed->precision == -1);
	assert(fmt[0] == ';');
	free(parsed);
	fmt = "#xNext";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'x');
	assert(parsed->hash == 1);
	assert(fmt[0] == 'N');
	free(parsed);
	fmt = "cEnd";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'c');
	assert(parsed->width == -2);
	assert(parsed->precision == -2);
	assert(fmt[0] == 'E');
	free(parsed);
	fmt = "-+ #012.*dX";
	parsed = ft_parse_fmt(&fmt);
	assert(parsed->specifier == 'd');
	assert(parsed->minus == 1);
	assert(parsed->plus == 1);
	assert(parsed->space == 1);
	assert(parsed->hash == 1);
	assert(parsed->zero == 1);
	assert(parsed->width == 12);
	assert(parsed->precision == -1); // from *
	assert(fmt[0] == 'X');
	free(parsed);
    printf("All tests passed!\n");
}

int main() {
    test_ft_parse_fmt();
    return 0;
}
