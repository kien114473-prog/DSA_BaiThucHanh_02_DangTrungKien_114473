#include <stdio.h>
#include <stdlib.h>
int main() {
    int h, c;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &h, &c);
    int *ma = (int *)malloc(h * c * sizeof(int));
    if (ma == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }
    printf("Nhap cac phan tu cho ma tran %dx%d:\n", h, c);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", ma + i * c + j); 
        }
    }
    printf("\nMa tran %dx%d vua tao:\n", h, c);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", *(ma + i * c + j));
        }
        printf("\n");
    }
    free(ma);
    return 0;
}
