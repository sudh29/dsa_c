#include <stdio.h>

int main(void) {
    printf("=== Compiler and System Details ===\n");
#if defined(__clang__)
    printf("Compiler: Clang %s\n", __clang_version__);
#elif defined(__GNUC__)
    printf("Compiler: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif

#if defined(__STDC_VERSION__)
    printf("C Standard (__STDC_VERSION__): %ldL\n", __STDC_VERSION__);
#endif
    printf("Pointer size: %zu-bit\n", sizeof(void*) * 8);
    return 0;
}
