#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random hexadecimal string
void generate_random_hex(char *str, size_t length) {
    const char hex_digits[] = "0123456789abcdef";
    for (size_t i = 0; i < length - 1; i++) {
        str[i] = hex_digits[rand() % 16];
    }
    str[length - 1] = '\0';  // Null-terminate the string
}

int main() {
    const char *flag = "af6f59b65684b4f887051535d9069219";
    char random_str[33];  // 32 hex chars + null terminator
    
    srand(time(NULL));  // Seed random number generator

    // Print 30 random strings to stdout
    for (int i = 0; i < 30; i++) {
        generate_random_hex(random_str, sizeof(random_str));
        printf("%s\n", random_str);
    }

    // Print flag to stderr
    fprintf(stderr, "%s\n", flag);

    return 0;
}
