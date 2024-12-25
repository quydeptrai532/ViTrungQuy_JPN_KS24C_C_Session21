#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char kyTu;

    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep bt01.txt de doc.\n");
        return 1;
    }

    kyTu = fgetc(file);
    if (kyTu != EOF) {
        printf("Ky tu dau tien trong tep: %c\n", kyTu);
    } else {
        printf("Tep bt01.txt trong hoac khong co noi dung.\n");
    }

    fclose(file);
    return 0;
}

