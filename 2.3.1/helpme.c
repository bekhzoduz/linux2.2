#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // "Welcome to helpme!" ni chop etamiz
    printf("Welcome to helpme!\n");

    // Agar argumentlar soni 2 yoki undan ko'p bo'lsa va argument "-flag" bo'lsa
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        // Bayroqni chop etamiz
        printf("-h/--help: show the help menu\n");
        printf("-f/--flag: show out the hidden flag\n");

    }


    if (argc > 1 && strcmp(argv[1], "-flag") == 0) {
        // Bayroqni chop etamiz
        printf("The flag is: HD{mage_ustasi_siri_yurishlar_bilan_muvaffaqiyatga_erishish} \n");
    }

    return 0;
}
