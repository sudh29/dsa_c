#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Three-way comparison function returning <0, 0, or >0 (standard C idiom)
static inline int compare_ints(int a, int b) {
    return (a > b) - (a < b);
}

int main(void) {
    printf("=== C Three-Way Comparison Idioms ===\n");
    int a = 10, b = 20;
    int cmp = compare_ints(a, b);

    if (cmp < 0) {
        printf("%d is less than %d\n", a, b);
    } else if (cmp == 0) {
        printf("%d is equal to %d\n", a, b);
    } else {
        printf("%d is greater than %d\n", a, b);
    }

    bool result = compare_ints(10, 20) > 0;
    printf("Result of (compare_ints(10, 20) > 0): %s\n", result ? "true" : "false");

    // Standard library 3-way string comparison demonstration
    const char *s1 = "apple";
    const char *s2 = "banana";
    printf("strcmp(\"%s\", \"%s\") = %d (< 0 means earlier in lexicographic order)\n",
           s1, s2, strcmp(s1, s2));

    return 0;
}
