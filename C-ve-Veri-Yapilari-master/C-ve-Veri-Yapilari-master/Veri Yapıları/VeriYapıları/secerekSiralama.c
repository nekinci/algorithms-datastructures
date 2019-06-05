#include<stdio.h>
#include<stdlib.h>
#define boyut 8

struct n{
    int data;
    struct n *next;
};
typedef struct n node;
void ekle(node * A,int data){
    while(A->next!=NULL)
        A=A->next;
    A->next=(node*) malloc(sizeof(node));
    A->next->data=data;
    A->next->next=NULL;

}


void bastir(int dizi[]){
    for(int i=0;i<boyut;i++){
        printf("%d ",dizi[i]);
    }
}

node * selectionSort(node *r){
    if(r==NULL){
        printf("LinkList Boş!");
        return NULL;
    }
    node *iter=r;
    for(node *i=iter;i->next->next!=NULL;i->next){
        node *min=i;
        for(node *j=i;j->next!=NULL;j++){
            if(j->data<min->data){
                min=j;
            }
        }
        int tmp=i->data;
        i->data=min->data;
        min->data=tmp;
    }
    return iter;
}
int main(){
    int dizi[]={5,7,3,1,2,8,4,6};
    printf("Sıralanmamış hali: ");
    bastir(dizi);
    for(int i=0;i<boyut-1;i++){
        int min;
        min=i;
        for(int j=i;j<boyut;j++){
            if(dizi[j]<dizi[min])
                min=j;
        }
        int tmp=dizi[i];
        dizi[i]=dizi[min];
        dizi[min]=tmp;
    }
    printf("\nSıralanmış hali:  ");
    bastir(dizi);

    node *root=NULL;
    root=(node*) malloc(sizeof(node));
    root->data=8;
    root->next=NULL;
    printf("\n\nLinkList: ");
    for(int i=0;i<boyut-1;i++){
        ekle(root,boyut-1-i);
    }
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
    printf("\nLinkList (sıralanmış hali): ");
    root=selectionSort(root);
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}
