#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    // Define the directory path
    const char *dir_path = "/home/hermes/FullOfStuff";
    
    // Check if the directory exists
    struct stat statbuf;
    if (stat(dir_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
        printf("HD{taking_out_the_trash_is_not_so_fun}\n");
    } else {
        printf("The directory 'FullOfStuff' does not exist.\n");
    }
    
    return 0;
}
