#include <stdio.h>

int main() {
    const char *filename = "pmgg-notes.txt";

    // Faylni yaratish
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not create the file %s\n", filename);
        return 1;
    }

    // Flagni faylga yozish
    fprintf(file, "HD{dunyodagi_eng_ajoyib_mage_oyini!}\n");

    // Faylni yopish
    fclose(file);

    printf("File %s created successfully with the content.\n", filename);

    return 0;
}
