#include <stdio.h>
#include <string.h>

#define FLAG "hello_mega_file"  // Correct flag identifier

int main() {
    char buffer[256];  // Buffer to read input content

    // Read the redirected input from stdin
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    // Compare the input with the flag
    if (strstr(buffer, FLAG) != NULL) {
        printf("HD{<_fayl_natijasini_dasturga_qayta_yo‘naltiradi}\n");  // Correct flag message
    } else {
        printf("incorrect\n");
    }

    return 0;
}