#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char dong[1000];

    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep bt01.txt de doc.\n");
        return 1;
    }

    if (fgets(dong, sizeof(dong), file) != NULL) {
        printf("Dong dau tien trong tep: %s", dong);
    } else {
        printf("Tep bt01.txt trong hoac khong co noi dung.\n");
    }

    fclose(file);
    return 0;
}

