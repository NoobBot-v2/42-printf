#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Function prototype
char *ft_to_hexbase(uintptr_t uptr);

// Helper to run and compare results
void test_hex(void *ptr, const char *desc) {
    uintptr_t uptr = (uintptr_t)ptr;
    char *hex_str = ft_to_hexbase(uptr);
    printf("Test: %s\n", desc);
    printf("Input ptr: %p\n", ptr);
    printf("Output string: %s\n\n", hex_str);
    free(hex_str);
}

int main() {
    // Test case 1: NULL pointer
    test_hex(NULL, "NULL pointer");

    // Test case 2: Address of a stack variable
    int a = 42;
    test_hex(&a, "Stack variable");

    // Test case 3: Address of a heap allocation
    int *heap_ptr = malloc(sizeof(int));
    *heap_ptr = 100;
    test_hex(heap_ptr, "Heap allocated variable");
    free(heap_ptr);

    // Test case 4: Address of a function
    test_hex((void *)ft_to_hexbase, "Function pointer");

    return 0;
}
