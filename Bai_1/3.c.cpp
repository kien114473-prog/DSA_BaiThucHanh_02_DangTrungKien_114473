#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ten[30];
    int masv;
    float d1, d2, d3;
} SinhVien;
void nhap(SinhVien *ds, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        scanf(" %[^\n]", (ds + i)->ten);
        printf("Ma SV: ");
        scanf("%d", &(ds + i)->masv);
        printf("Diem 1: ");
        scanf("%f", &(ds + i)->d1);
        printf("Diem 2: ");
        scanf("%f", &(ds + i)->d2);
        printf("Diem 3: ");
        scanf("%f", &(ds + i)->d3);
    }
}
void in(SinhVien *ds, int n) {
    int i;
    printf("\n=== DANH SACH SINH VIEN DA NHAP ===\n");
    for (i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ho ten: %s\n", (ds + i)->ten);
        printf("Ma SV: %d\n", (ds + i)->masv);
        printf("Diem 1: %.2f\n", (ds + i)->d1);
        printf("Diem 2: %.2f\n", (ds + i)->d2);
        printf("Diem 3: %.2f\n", (ds + i)->d3);
    }
}
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong sinh vien khong hop le!\n");
        return 0;
    }
    SinhVien *ds = (SinhVien*) malloc(n * sizeof(SinhVien));
    if (ds == NULL) {
        printf("Khong du bo nho de cap phat\n");
        return 0;
    }
    nhap(ds, n);
    printf("\n================ DANH SACH SINH VIEN DA NHAP ================");
    in(ds, n);
    free(ds);
    return 0;
}
