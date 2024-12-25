#include <stdio.h>
#include <stdlib.h>

int main() {
    int soDong;
    char dong[1000];
    FILE *file;

    file = fopen("bt05.txt", "w");
    if (file == NULL) {
        printf("Khong the tao tep bt05.txt.\n");
        return 1;
    }

    printf("Nhap so dong can ghi: ");
    scanf("%d", &soDong);
    getchar();

    for (int i = 0; i < soDong; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(dong, sizeof(dong), stdin);
        fprintf(file, "%s", dong);
    }

    fclose(file);
    printf("Da ghi noi dung vao tep bt05.txt thanh cong.\n");

    return 0;
}

