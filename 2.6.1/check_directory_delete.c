#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    // Katalog manzili
    const char *dir_path = "/home/hermes/FullOfStuff";

    // Katalog mavjudligini tekshirish
    struct stat statbuf;
    if (stat(dir_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
        printf("Xato: 'FullOfStuff' katalogi mavjud. Iltimos, uni o'chiring.\n");
        return 1; // Xato kodi
    } else {
        printf("flag: HD{axlatni_olib_chiqish_juda_qiziq_emas}\n");
    }

    return 0;
}
