#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *dir_path = "/home/athena/MassiveFiles";
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    int found_unwanted = 0;

    if (dir == NULL) {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (entry->d_name[0] == 'A') {
            found_unwanted = 1;
        }
        int len = strlen(entry->d_name);
        if (len >= 4 && strcmp(entry->d_name + len - 4, ".pdf") == 0) {
            found_unwanted = 1;
        }
        if (strpbrk(entry->d_name, "0123456789") != NULL) {
            found_unwanted = 1;
        }
        if (found_unwanted) {
            break;
        }
    }

    closedir(dir);

    if (found_unwanted) {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
        return 1;
    }

    printf("HD{qiyin_shartlar_qiyin_vaqtlarni_keltiradi}\n");
    return 0;
}
