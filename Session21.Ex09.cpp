#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[100];
    char author[100];
    float price;
    char genre[50];
};

void nhapThongTinSach(struct Book *book) {
    printf("Nhap ma sach: ");
    scanf("%d", &book->id);
    getchar(); 

    printf("Nhap ten sach: ");
    fgets(book->name, sizeof(book->name), stdin);
    book->name[strcspn(book->name, "\n")] = 0;

    printf("Nhap tac gia: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = 0;

    printf("Nhap gia tien: ");
    scanf("%f", &book->price);
    getchar(); 

    printf("Nhap the loai: ");
    fgets(book->genre, sizeof(book->genre), stdin);
    book->genre[strcspn(book->genre, "\n")] = 0;
}

void luuThongTinSach(struct Book *books, int soLuong) {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    fwrite(books, sizeof(struct Book), soLuong, file);
    fclose(file);
    printf("Da luu thong tin sach vao file.\n");
}

void layThongTinSach(struct Book *books, int *soLuong) {
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    *soLuong = fread(books, sizeof(struct Book), 100, file);
    fclose(file);
    printf("Da lay thong tin sach tu file.\n");
}

void hienThiThongTinSach(struct Book *books, int soLuong) {
    if (soLuong == 0) {
        printf("Khong co sach trong danh sach.\n");
        return;
    }
    for (int i = 0; i < soLuong; i++) {
        printf("Ma sach: %d\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].genre);
        printf("-----------------------------\n");
    }
}

int main() {
    struct Book books[100];
    int soLuong = 0;
    int luaChon;

    while (1) {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &soLuong);
                getchar();
                for (int i = 0; i < soLuong; i++) {
                    printf("Nhap thong tin sach %d:\n", i + 1);
                    nhapThongTinSach(&books[i]);
                }
                break;
            case 2:
                luuThongTinSach(books, soLuong);
                break;
            case 3:
                layThongTinSach(books, &soLuong);
                break;
            case 4:
                hienThiThongTinSach(books, soLuong);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}

