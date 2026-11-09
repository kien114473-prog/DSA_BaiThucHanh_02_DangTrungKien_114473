#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;
typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int main() {
    LList L;
    initList(&L);
    printf("Da khai bao va khoi tao danh sach lien ket don sinh vien thanh cong\n");
    return 0;
}
