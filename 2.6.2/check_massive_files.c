#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *dir_path = "/home/athena/MassiveFiles";
    struct dirent *entry;
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == 'A' || strstr(entry->d_name, ".pdf") != NULL ||
            strpbrk(entry->d_name, "0123456789") != NULL) {
            printf("Siz topshiriqni to'liq bajarmadingiz.\n");
            closedir(dir);
            return 1;
        }
    }

    closedir(dir);
    printf("HD{qiyin_shartlar_qiyin_vaqtlarni_keltiradi}\n");
    return 0;
}
