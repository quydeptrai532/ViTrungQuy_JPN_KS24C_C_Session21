#include <stdio.h>
#include <stdlib.h>

int main() {
    char chuoi[1000];
    FILE *file;

    printf("Nhap mot chuoi bat ky de ghi them: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    file = fopen("bt01.txt", "a");
    if (file == NULL) {
        printf("Khong the mo tep bt01.txt de ghi them.\n");
        return 1;
    }

    fprintf(file, "%s", chuoi);
    fclose(file);

    printf("Da ghi them chuoi vao tep bt01.txt thanh cong.\n");
    return 0;
}

