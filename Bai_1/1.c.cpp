#include <stdio.h>
#include <stdlib.h>

void nhap(float *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Nhap ptu thu %d: ", i);
        scanf("%f", a + i);
    }
}

void in(float *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2f ", *(a + i));
    }
    printf("\n");
}

int main() {
    float *a;
    int n;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    a = (float*) malloc(n * sizeof(float));

    nhap(a, n);
    printf("\nDL ban dau:\n");
    in(a, n);

    free(a);
    a = NULL;
    return 0;
}
