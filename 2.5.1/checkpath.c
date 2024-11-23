// path_check.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* required_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/"; // Kerakli yo'lni kiriting
    const char* env_path = getenv("PATH"); // PATH muhit o'zgaruvchisini olish

    if (env_path == NULL) {
        printf("Error: PATH environment variable not found!\n");
        return 1;
    }

    // PATH o'zgaruvchisida kerakli yo'l mavjudligini tekshirish
    if (strcmp(env_path, required_path) == 0) {
        printf("Correct path! Here is your flag : HD{mojarosiz_birlik_yoli_togrilik_va_betartibliksiz}\n");
    } else {
        printf("Incorrect path. Please check your environment.\n");
    }

    return 0;
}
