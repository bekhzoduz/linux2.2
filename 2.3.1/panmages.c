

// panmages.c
#include <stdio.h>
#include <string.h>

void flip_P_and_M() {
    printf("If you flip the 'P' and 'M', it makes a lot more sense!\n");
}

int main() {
    char input[50];
    FILE *file;  // Declare file pointer

    printf("Enter the name of the game: ");
    scanf("%49s", input);
    
    if (strcmp(input, "manpages") == 0) {
        // Open the file for writing (create if it doesn't exist)
        file = fopen("flag.txt", "w");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        // Write the flag to the file
        fprintf(file, "Flag: HD{M_va_P_harflarini_almashtirsangiz_qiziqroq_bo'ladi}\n");
        fclose(file);  // Close the file
        printf("Flag has been written to game-gide.txt\n");
    } else {
        flip_P_and_M();
    }

    return 0;
}
