#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *more_files_path = "/home/athena/MoreFiles";
    const char *athena_docs_path = "/home/athena/MoreFiles/Athena Documents";
    struct dirent *entry;
    DIR *more_files_dir = opendir(more_files_path);
    DIR *athena_docs_dir = opendir(athena_docs_path);
    int more_files_txt_count = 0;
    int athena_docs_txt_count = 0;

    if (more_files_dir == NULL || athena_docs_dir == NULL) {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
        return 1;
    }

    while ((entry = readdir(more_files_dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") != NULL) {
            more_files_txt_count++;
        }
    }

    while ((entry = readdir(athena_docs_dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") != NULL) {
            athena_docs_txt_count++;
        }
    }

    closedir(more_files_dir);
    closedir(athena_docs_dir);

    if (more_files_txt_count == 0 && athena_docs_txt_count > 0) {
        printf("HD{wildcardlar_juda_qiziqarli!}\n");
    } else {
        printf("Siz topshiriqni to'liq bajarmadingiz.\n");
    }

    return 0;
}
