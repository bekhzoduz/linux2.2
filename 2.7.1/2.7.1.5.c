#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;

    char *users[] = {"bill", "john", "tom", "sam"};
    for (int i = 0; i < 4; i++) {
        char command[50];
        snprintf(command, sizeof(command), "sudo useradd %s", users[i]);
        status = system(command);

        if (status == -1) {
            printf("Error: Failed to execute useradd for %s.\n", users[i]);
            return 1;
        }
    }

    printf("Users bill, john, tom, and sam have been created successfully.\n");

    return 0;
}
