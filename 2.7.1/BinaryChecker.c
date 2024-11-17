#include <stdio.h>
#include <string.h>

#define FLAG "hello_mega_file"  // Correct flag identifier

int main(int argc, char *argv[]) {
    char buffer[256];  // Buffer to read file content
    FILE *file;

    // Check if a file name is provided
    if (argc < 2) {
        printf("Error: Please provide a file name as input.\n");
        return 1;
    }

    // Open the provided file in read mode
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open the file %s\n", argv[1]);
        return 1;
    }

    // Read the file content into the buffer (up to 255 characters + null terminator)
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Error: Failed to read the file content.\n");
        fclose(file);
        return 1;
    }
    fclose(file);  // Close the file after reading

    // Compare the file content with the flag
    if (strstr(buffer, FLAG) != NULL) {
        printf("HD{<_fayl_natijasini_dasturga_qayta_yo‘naltiradi}\n");  // Correct flag message
    } else {
        printf("incorrect\n");
    }

    return 0;
}
