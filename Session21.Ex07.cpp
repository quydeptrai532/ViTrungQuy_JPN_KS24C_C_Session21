#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int id;
    char name[100];
    int age;
};

int main() {
    int soLuongSinhVien;
    struct SinhVien sv;
    FILE *file;

    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Khong the tao tep students.txt.\n");
        return 1;
    }

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &soLuongSinhVien);
    getchar(); 
    for (int i = 0; i < soLuongSinhVien; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        
        printf("ID: ");
        scanf("%d", &sv.id);
        getchar();

        printf("Ten: ");
        fgets(sv.name, sizeof(sv.name), stdin);

        printf("Tuoi: ");
        scanf("%d", &sv.age);
        getchar(); 

        fprintf(file, "%d %s %d\n", sv.id, sv.name, sv.age);
    }

    fclose(file);
    printf("Da luu thong tin sinh vien vao tep students.txt thanh cong.\n");

    return 0;
}

