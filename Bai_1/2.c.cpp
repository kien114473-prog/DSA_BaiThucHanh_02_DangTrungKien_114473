#include <stdio.h>
#include <stdlib.h>

void nhap(float *a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%f", a + i * m + j);
        }
    }
}

void in(float *a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%.2f ", *(a + i * m + j));
        }
        printf("\n");
    }
}

int main() {
    float *a;
    int n, m;

    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &n, &m);

    a = (float*) malloc(n * m * sizeof(float));

    nhap(a, n, m);
    printf("\nDL ban dau:\n");
    in(a, n, m);

    free(a);
    a = NULL;
    return 0;
}
