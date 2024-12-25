#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int id;
    char name[100];
    int age;
};

int main() {
    struct SinhVien sinhVien[100];
    int soLuongSinhVien = 0;
    FILE *file;

    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep students.txt.\n");
        return 1;
    }

    while (fscanf(file, "%d %[^\n] %d", &sinhVien[soLuongSinhVien].id, sinhVien[soLuongSinhVien].name, &sinhVien[soLuongSinhVien].age) != EOF) {
        soLuongSinhVien++;
        if (soLuongSinhVien >= 100) {
            printf("Mang sinh vien da day.\n");
            break;
        }
    }

    fclose(file);

    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuongSinhVien; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", sinhVien[i].id, sinhVien[i].name, sinhVien[i].age);
    }

    return 0;
}

