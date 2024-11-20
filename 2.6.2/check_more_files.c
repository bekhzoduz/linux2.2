#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *dir_path = "/home/athena/MoreFiles/Athena Documents";
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    int txt_count = 0;

    if (dir == NULL) {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") != NULL) {
            txt_count++;
        }
    }

    closedir(dir);

    if (txt_count > 0) {
        printf("HD{wildcardlar_juda_qiziqarli!}\n");
    } else {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
    }

    return 0;
}
