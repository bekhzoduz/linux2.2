#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the file path
    const char *file_path = "/home/hermes/fast.txt";

    // Try to open the file
    FILE *file = fopen(file_path, "r");

    // Check if the file exists
    if (file) {
        printf("HD{its_all_greek_to_me}\n");
        fclose(file); // Close the file if it exists
    } else {
        printf("The file 'fast.txt' does not exist in the /home/hermes/ directory.\n");
    }

    return 0;
}
