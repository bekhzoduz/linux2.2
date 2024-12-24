#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // .bashrc faylini o'qish
    FILE *bashrc = fopen("/home/eris/.bashrc", "r");
    if (bashrc == NULL) {
        printf(".bashrc faylini o'qishda xato!\n");
        return 1;
    }

    // Alias qatorini tekshirish
    char *alias_line = "alias ls=\"echo \\\"ls buyrug‘i ishlamaydi!\\\"\"";
    char line[256];
    int alias_found = 0;

    while (fgets(line, sizeof(line), bashrc) != NULL) {
        if (strcmp(line, alias_line) == 0) {
            alias_found = 1; // Alias topildi
            break;
        }
    }
    fclose(bashrc); // Faylni yopish

    // Agar alias topilsa, flag bermaymiz
    if (alias_found) {
        printf("ls buyrug‘i ishlamaydi! (alias mavjud)\n");
        return 0; // Dastur tugaydi
    }

    // 'ls' buyrug'ini chaqirish va natijasini o'qish
    FILE *fp;
    char path[1035];

    fp = popen("ls", "r");
    if (fp == NULL) {
        printf("ls buyrug‘i ishlamaydi!\n");
        return 1;
    }

    // 'ls' buyrug'ining chiqishini tekshirish
    int found = 0;
    while (fgets(path, sizeof(path) - 1, fp) != NULL) {
        if (strstr(path, "checkpath") != NULL) {
            found = 1; // "checkpath" topildi
            break;
        }
    }

    // Popendani yopish
    pclose(fp);

    // Natijani chiqarish
    if (found) {
        printf("ls buyrug‘i muvaffaqiyatli bajarildi. \"checkpath\" topildi.\n");
        printf("HD{aliasni_ishlatish_meni_sirli_agentdek_his_qildiradi}\n");
    } else {
        printf("ls buyrug‘i ishlamaydi!\n");
    }

    return 0;
}
