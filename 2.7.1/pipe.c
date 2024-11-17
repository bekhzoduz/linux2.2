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

int main(int argc, char *argv[]) {
    // Check if file name is provided as argument
    if (argc < 2) {
        printf("Error: Please provide a file name as a parameter.\n");
        return 1;
    }

    // Correct flag
    const char *correct_flag = "af6f59b65684b4f887051535d9069219\n";
    char random_flag[33];  // Hexadecimal flag of length 32 + 1 for null-terminator
    
    srand(time(NULL));  // Seed the random number generator

    // Loop to generate 30 flags
    for (int i = 1; i <= 30; i++) {
        // If it's the last iteration (30th), print the correct flag
        if (i == 30) {
            printf("%s", correct_flag);
        } else {
            generate_random_hex(random_flag, sizeof(random_flag));
            printf("%s", random_flag);  // Print a random flag
        }
    }

    // Open the input file (name.txt) and write the correct flag to it
    FILE *input_file = fopen(argv[1], "w");
    if (input_file == NULL) {
        printf("Error: Could not open %s for writing.\n", argv[1]);
        return 1;
    }

    // Write the correct flag to the file passed as input
    fprintf(input_file, "%s", correct_flag);
    fclose(input_file);

    printf("Successfully wrote the correct flag to %s\n", argv[1]);

    return 0;
}
