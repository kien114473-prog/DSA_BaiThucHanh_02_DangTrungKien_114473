#include<stdio.h>
#include<stdlib.h>
typedef struct    {
     char hoten[30];
     int masv;
     float d1, d2, d3;
}Data;
typedef struct tagNode    {
     Data infor;
     struct tagNode *link;
}Node;
typedef struct    {
     Node *pHead;  
     Node *pTail;
     int spt;
}LList;
/////////////////////////////////////
void initList(LList *L)
    {
     L->pHead = NULL;
     L->pTail = NULL;
     L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L)
 {
     return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
    {
     Node *pp;
     pp = (Node*) malloc(sizeof(Node));
     pp->infor = x;
     pp->link = NULL;
     if(emptyList(*L)){
       L->pHead = pp;
       L->pTail = pp;
      }   
        else {
      pp->link = L->pHead;
      L->pHead = pp;
      }
     L->spt++;
    }
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ma sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
         in(pp->infor); 
         pp = pp->link;
     }
}
/////////////////////////////////////////
int main(){
    LList L;
 int kt = 0;
 Data x;
 initList(&L);
 do{
     printf("\nChuong trinh lam viec voi DSLK don SV\n");
     printf("\n1: Them nut vao dau danh sach");
     printf("\n2: Them nut vao cuoi danh sach");
     printf("\n3: Them nut vao sau mot nut khac trong danh sach");
     printf("\n9: Duyet ds");
     printf("\n0: Thoat");
     printf("\nMoi ban chon: ");
     int chon;
     scanf("%d", &chon);
     switch(chon){
         case 1: 
	            printf("Nhap thong tin sv can them vao dau\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sv can them vao cuoi\n");
	            nhap(&x);
	            if(x.masv > 0)
	            	insert_Tail(&L, x);
            	break;
            case 3:{
            	printf("Nhap thong tin sinh vien can them\n");
	            nhap(&x);
	            printf("Nhap ma sinh vien can them vao sau\n");
	            int ma;
	            scanf("%d", &ma);
	            Node *q = L.pHead;
	            while(q != NULL && q->infor.masv != ma){
	            	q = q->link;
				}
	            
	            if(x.masv > 0){
	            	insert_After(&L, q, x);
				}
            	break;
			}
            case 4: 
            {
            	int masv_xoa;
            	printf("Nhap ma sv can xoa: ");
            	scanf("%d", &masv_xoa);
            	if(delete_Node(&L, masv_xoa)){
            		printf("Xoa thanh cong sv ma %d\n", masv_xoa);
				}else{
					printf("Khong tim thay sv ma %d de xoa\n", masv_xoa);
				}
                break;
            }
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
             kt = 1;
        }
 }while(kt==0); 
}
