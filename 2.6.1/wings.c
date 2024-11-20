#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char actual_path[PATH_MAX];
    const char *symlink_path = "./wings";

    // Symlinkdan haqiqiy yo'lni olish
    if (realpath(symlink_path, actual_path) != NULL) {
        printf("%s\n", actual_path);
    } else {
        perror("Error: ");
    }

    return 0;
}
