#include <stdio.h>

int main(void) {
    printf("=== C Standard Hello & I/O ===\n");
    const char *greeting = "Hello from DSA in Pure C (C11)!";
    printf("%s\n", greeting);

    // Formatted string buffer (equivalent to stringstream)
    char formatted[128];
    int year = 2026;
    snprintf(formatted, sizeof(formatted), "Year: %d | Status: Ready", year);
    printf("%s\n", formatted);
    return 0;
}
