#include <stdio.h>

int main() {
    // Define the file path
    const char *filename = "/home/artemis/field_of_flags.csv";

    // Open the file for writing
    FILE *file = fopen(filename, "w");

    // Check if the file was created successfully
    if (file == NULL) {
        printf("Error: Could not create the file %s\n", filename);
        return 1;
    }

    // Write 12 dummy lines
    for (int i = 1; i <= 12; i++) {
        fprintf(file, "field%d_1,field%d_2,field%d_3,field%d_4\n", i, i, i, i);
    }

    // Write the 13th line with the flag
    fprintf(file, "HD{agar_sen_buni_qursang_ular_keladi}\n");

    // Close the file
    fclose(file);

    printf("File %s created successfully with the flag on line 13.\n", filename);

    return 0;
}
